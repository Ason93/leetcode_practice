#include <iostream>
#include <vector>

using namespace std;

class Solution {

  /*********************************************************
  36. Valid Sudoku
  Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
  validated according to the following rules: Each row must contain the digits
  1-9 without repetition. Each column must contain the digits 1-9 without
  repetition. Each of the nine 3 x 3 sub-boxes of the grid must contain the
  digits 1-9 without repetition.

  Note:
  A Sudoku board (partially filled) could be valid but is not necessarily
  solvable. Only the filled cells need to be validated according to the
  mentioned rules.

  Example 1:
  Input: board =
  [['5','3','.','.','7','.','.','.','.']
  ,['6','.','.','1','9','5','.','.','.']
  ,['.','9','8','.','.','.','.','6','.']
  ,['8','.','.','.','6','.','.','.','3']
  ,['4','.','.','8','.','3','.','.','1']
  ,['7','.','.','.','2','.','.','.','6']
  ,['.','6','.','.','.','.','2','8','.']
  ,['.','.','.','4','1','9','.','.','5']
  ,['.','.','.','.','8','.','.','7','9']]
  Output: true

  Example 2:
  Input: board =
  [['8','3','.','.','7','.','.','.','.']
  ,['6','.','.','1','9','5','.','.','.']
  ,['.','9','8','.','.','.','.','6','.']
  ,['8','.','.','.','6','.','.','.','3']
  ,['4','.','.','8','.','3','.','.','1']
  ,['7','.','.','.','2','.','.','.','6']
  ,['.','6','.','.','.','.','2','8','.']
  ,['.','.','.','4','1','9','.','.','5']
  ,['.','.','.','.','8','.','.','7','9']]
  Output: false
  Explanation: Same as Example 1, except with the 5 in the top left corner being
  modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is
  invalid.
  *********************************************************/
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    const int row = board.size();
    const int col = board[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (board[i][j] != '.') {
          char c = board[i][j];
          if (!isValid1(board, i, j, c)) {
            return false;
          }
        }
      }
    }
    return true;
  }

private:
  bool isValid1(vector<vector<char>> &board, int i, int j, char c) {
    const int n = board.size();
    for (int k = 0; k < n; k++) {
      if (j != k && c == board[i][k]) {
        return false;
      }
      if (i != k && c == board[k][j]) {
        return false;
      }
      if (3 * (i / 3) + k / 3 != i && 3 * (j / 3) + k % 3 != j &&
          c == board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3]) {
        return false;
      }
    }
    return true;
  }

  /*********************************************************
  37. Sudoku Solver
  Write a program to solve a Sudoku puzzle by filling the empty cells.
  A sudoku solution must satisfy all of the following rules:
  Each of the digits 1-9 must occur exactly once in each row.
  Each of the digits 1-9 must occur exactly once in each column.
  Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes
  of the grid. The '.' character indicates empty cells.

  Example 1:
  Input: board =
  [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
  Output:
  [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
  Explanation: The input board is shown above and the only valid solution is
  shown below:
  *********************************************************/
public:
  void solveSudoku(vector<vector<char>> &board) {
    Sudoku(board);
    return;
  }

private:
  bool Sudoku(vector<vector<char>> &board) {
    const int row = board.size();
    const int col = board[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (board[i][j] == '.') {
          for (char c = '1'; c <= '9'; c++) {
            if (isValid2(board, i, j, c)) {
              board[i][j] = c;
              if (Sudoku(board)) {
                return true;
              } else {
                board[i][j] = '.';
              }
            }
          }
          return false;
        }
      }
    }
    return true;
  }
  bool isValid2(vector<vector<char>> &board, int i, int j, char c) {
    const int n = board.size();
    for (int k = 0; k < n; k++) {
      if (board[i][k] != '.' && board[i][k] == c) {
        return false;
      }
      if (board[k][j] != '.' && board[k][j] == c) {
        return false;
      }
      if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] != '.' &&
          board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c) {
        return false;
      }
    }
    return true;
  }
};

int main() {

  Solution S;

  vector<vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  S.isValidSudoku(board);
  S.solveSudoku(board);

  return 0;
}