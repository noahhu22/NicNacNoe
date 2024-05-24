#include <iostream>
#include <string>

// command to run game: g++ -std=c++11 NicNacNoe.cpp -o game.exe

int main();

//All global variables needed
int game_board[9] = {0,0,0,0,0,0,0,0,0};
char final_board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
std::string player1, player2;

//Function Declarations
void clear_board();
void print_row();
void print_special_row();
int is_game_won(int board[]);
void start_game();
void make_move(int player);
void print_board(int board[]);

//Function Definitions

void clear_board(){
    for(int i{0}; i<9; i++){
        game_board[i] = 0;
        final_board[i] = ' ';
    }
}

void print_row(){
    std::cout << " | | " << std::endl;
}

void print_special_row(){
    std::cout << "-------------" << std::endl;
}

int is_game_won(int board[]){
    int count{0};
    for(int i{0};i<9;i++){
        if(board[i]==0){
            break;
        }
        else{
            count++;
        }
        if(count==9){
            return 9;
        }
    }
    if(board[0] == 1 && board[1] == 1 && board[2] == 1){
        return 1;
    }
    if(board[3] == 1 && board[4] == 1 && board[5] == 1){
        return 1;
    }
    if(board[6] == 1 && board[7] == 1 && board[8] == 1){
        return 1;
    }
    if(board[0] == 1 && board[3] == 1 && board[6] == 1){
        return 1;
    }
    if(board[1] == 1 && board[4] == 1 && board[7] == 1){
        return 1;
    }
    if(board[2] == 1 && board[5] == 1 && board[8] == 1){
        return 1;
    }
    if(board[0] == 1 && board[4] == 1 && board[8] == 1){
        return 1;
    }
    if(board[2] == 1 && board[4] == 1 && board[6] == 1){
        return 1;
    }
    
    if(board[0] == 2 && board[1] == 2 && board[2] == 2){
        return 2;
    }
    if(board[3] == 2 && board[4] == 2 && board[5] == 2){
        return 2;
    }
    if(board[6] == 2 && board[7] == 2 && board[8] == 2){
        return 2;
    }
    if(board[0] == 2 && board[3] == 2 && board[6] == 2){
        return 2;
    }
    if(board[1] == 2 && board[4] == 2 && board[7] == 2){
        return 2;
    }
    if(board[2] == 2 && board[5] == 2 && board[8] == 2){
        return 2;
    }
    if(board[0] == 2 && board[4] == 2 && board[8] == 2){
        return 2;
    }
    if(board[2] == 2 && board[4] == 2 && board[6] == 2){
        return 2;
    }
    return 0;
}

void start_game(){
    std::cout << std::endl << "Welcome to NicNacNoe, a version of TicTacToe coded purely in C++ by the one and only Noah Hu." << std::endl;
    int player_num = 1;
    char play_again;
    std::cout << "Player 1, please enter your name." << std::endl;
    std::getline(std::cin, player1);
    std::cout << std::endl;
    std::cout << "Player 2, please enter your name." << std::endl;
    std::getline(std::cin, player2);
    std::cout << std::endl;
    print_board(game_board);
    while(is_game_won(game_board) == 0){
        make_move(player_num);
        print_board(game_board);
        player_num++;
    }
    if(is_game_won(game_board) == 1){
        std::cout << "Congratulations! " << player1 <<" has won the game!";
    }
    else if(is_game_won(game_board) == 2){
        std::cout << "Congratulations! " << player2 <<" has won the game!";
    }
    else{
        std::cout << "The game has ended in a draw.";
    }
    std::cout << std::endl << "Would you like to play again? Yes(Y), No(N)" << std::endl;
    std::cin >> play_again;
    std::cin.ignore();
    if(play_again == 'Y' || play_again == 'y'){
        clear_board();
        start_game();
    }
}

void make_move(int player){
    if(player % 2 == 1){
        int move{0};
        std::cout << player1 << ", please make your move. Your answer must be a digit from 1-9 where 1 represents the top left box and 9 represents the bottom right box.";
        std::cout << std::endl;
        std::cin >> move;
        while(move < 1 || move > 9){
            std::cout << "Please enter a valid box number." << std::endl;
            std::cin >> move;
        }
        while(game_board[move-1] != 0){
            std::cout << "That square is already taken, please choose another square." << std::endl;
            std::cin >> move;
        }
        game_board[move-1] = 1;
    }
    else{
        int move{0};
        std::cout << player2 << ", please make your move. Your answer must be a digit from 1-9 where 1 represents the top left box and 9 represents the bottom right box.";
        std::cout << std::endl;
        std::cin >> move;
        while(move < 1 || move > 9){
            std::cout << "Please enter a valid box number." << std::endl;
            std::cin >> move;
        }
        while(game_board[move-1] != 0){
            std::cout << "That square is already taken, please choose another square." << std::endl;
            std::cin >> move;
        }
        game_board[move-1] = 2;
    }
}

void print_board(int board[]){
    for(int i{0}; i<9;i++){
        if(board[i] == 1){
            final_board[i] = 'X';
        }
        else if(board[i] == 2){
            final_board[i] = 'O';
        }
    }
    std::cout << "| " << final_board[0] << " | " << final_board[1] << " | " << final_board[2] << " |" << std::endl;
    print_special_row();
    
    std::cout << "| " << final_board[3] << " | " << final_board[4] << " | " << final_board[5] << " |" << std::endl;
   
    print_special_row();
    
    std::cout << "| " << final_board[6] << " | " << final_board[7] << " | " << final_board[8] << " |" << std::endl;
    
    std::cout << std::endl;
}

int main(){
    start_game();
    return 0;
}