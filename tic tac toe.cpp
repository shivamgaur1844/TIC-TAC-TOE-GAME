#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_board(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |" << endl;
        cout << "-------------" << endl;
    }
}

bool check_win(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

bool check_draw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; 
        }
    }
    return true; 
}

void play_game() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    vector<char> players = {'X', 'O'};
    int current_player = 0;
    bool game_over = false;
    
    while (!game_over) {
        print_board(board);
        cout << "Player " << players[current_player] << "'s turn." << endl;
        
        // Get player move
        int move;
        while (true) {
            cout << "Enter your move (1-9): ";
            cin >> move;
            
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            
            if (move >= 1 && move <= 9 && board[row][col] == ' ') {
                board[row][col] = players[current_player];
                break;
            } else {
                cout << "Invalid move. Please try again." << endl;
            }
        }
        
        // Check if current player wins
        if (check_win(board, players[current_player])) {
            print_board(board);
            cout << "Player " << players[current_player] << " wins!" << endl;
            game_over = true;
        } else if (check_draw(board)) {
            print_board(board);
            cout << "It's a draw!" << endl;
            game_over = true;
        }
        
        current_player = 1 - current_player;
    }

    char rematch;
    cout << "Do you want to play again? (yes/no): ";
    cin >> rematch;
    if (rematch == 'y' || rematch == 'Y') {
        play_game();
    } else {
        cout << "Thanks for playing!" << endl;
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    play_game();
    return 0;
}
