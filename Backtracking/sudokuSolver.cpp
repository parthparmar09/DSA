#include <iostream>
#include <vector>
using namespace std;

bool canPlace(int row , int col , int val , vector<vector<char>> &board){
    char c = val + '0';
    //for row   
    for(int i = 0 ; i < 9 ; i++){
        if(board[row][i] == c){
            return false;
        }
    }
    //for col
    for(int i = 0 ; i < 9 ; i++){
        if(board[i][col]  == c){
            return false;
        }
    }
    //for mini-matrix
    int subrow = (row /3)*3;
    int subcol = (col /3)*3;

    for(int i = subrow ; i < subrow +3 ; i++){
        for(int j = subcol ; j <subcol + 3 ; j++){
            if(board[i][j] == c){
            return false;
        }
        }
    }

    return true;
}

bool solve(vector<vector<char>> &board , int row){

    for(int i = row ; i < board.size() ; i++){
        for(int j = 0 ; j < board.size() ; j++){
            if(board[i][j] == '.'){
                for(int k = 1 ;k <= 9 ; k++){
                    if(canPlace( i , j , k , board)){
                        board[i][j] = k + '0';
                        if(solve(board , i)){
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }
    return true;
}


void solveSudoku(vector<vector<char>> &board)
{
    solve(board , 0);

}


//from chatGPT
class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    bool solveSudokuHelper(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return solveSudokuHelper(board, row+1, 0);
        if (board[row][col] != '.') return solveSudokuHelper(board, row, col+1);

        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                if (solveSudokuHelper(board, row, col+1)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board, 0, 0);
    }
};
