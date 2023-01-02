#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  /****************************************
  51. N-Queens
  The n-queens puzzle is the problem of placing n queens on an n x n chessboard
  such that no two queens attack each other. Given an integer n, return all
  distinct solutions to the n-queens puzzle. You may return the answer in any
  order. Each solution contains a distinct board configuration of the n-queens'
  placement, where 'Q' and '.' both indicate a queen and an empty space,
  respectively.

  Example 1:
  Input: n = 4
  Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
  Explanation: There exist two distinct solutions to the 4-queens puzzle as
  shown above

  Example 2:
  Input: n = 1
  Output: [["Q"]]
  ****************************************/

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> results;
    _NQueens(n, 0, results, {}, {}, {});
    vector<vector<string>> queues = _generateQueens(results, n);
    return queues;
  }

  /****************************************
  52. N-Queens II
  The n-queens puzzle is the problem of placing n queens on an n x n chessboard
  such that no two queens attack each other. Given an integer n, return the
  number of distinct solutions to the n-queens puzzle. Example 1: Input: n = 4
  Output: 2
  Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

  Example 2:
  Input: n = 1
  Output: 1
  ****************************************/

  int totalNQueens(int n) {
    vector<vector<int>> results;
    _NQueens(n, 0, results, {}, {}, {});
    return results.size();
  }

private:
  void _NQueens(int n, int row, vector<vector<int>> &results, vector<int> col,
                vector<int> pie, vector<int> na) {
    if (row >= n) {
      results.emplace_back(col);
      return;
    }
    for (int c = 0; c < n; ++c) {
      vector<int>::iterator ic = find(col.begin(), col.end(), c);
      vector<int>::iterator ip = find(pie.begin(), pie.end(), row + c);
      vector<int>::iterator in = find(na.begin(), na.end(), row - c);
      if (ic == col.end() && ip == pie.end() && in == na.end()) {
        col.emplace_back(c);
        pie.emplace_back(row + c);
        na.emplace_back(row - c);
        _NQueens(n, row + 1, results, col, pie, na);
        col.pop_back();
        pie.pop_back();
        na.pop_back();
      }
    }
  }

  vector<vector<string>> _generateQueens(vector<vector<int>> &results, int n) {
    vector<vector<string>> queens;
    for (auto result : results) {
      vector<string> queen;
      for (auto col : result) {
        string q("");
        for (int c = 0; c < n; ++c) {
          if (c == col) {
            q += "Q";
          } else {
            q += ".";
          }
        }
        queen.emplace_back(q);
      }
      queens.emplace_back(queen);
    }
    return queens;
  }
};

// method bit
class Solution2 {
public:
  /****************************************
  52. N-Queens II
  The n-queens puzzle is the problem of placing n queens on an n x n chessboard
  such that no two queens attack each other. Given an integer n, return the
  number of distinct solutions to the n-queens puzzle. Example 1: Input: n = 4
  Output: 2
  Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

  Example 2:
  Input: n = 1
  Output: 1
  ****************************************/

  int totalNQueens(int n) {
    if (n < 1) {
      return 0;
    }
    count_ = 0;
    _NQueens(n, 0, 0, 0, 0);
    return count_;
  }

private:
  void _NQueens(int n, int row, int col, int pie, int na) {
    if (row >= n) {
      count_++;
      return;
    }
    int bits = (~(col | pie | na)) & ((1 << n) - 1); // get the available space
    while (bits) {
      int p = bits & (-bits); // get the lowest 1
      _NQueens(n, row + 1, col | p, (pie | p) << 1, (na | p) >> 1);
      bits &= bits - 1; // remove the lowest 1
    }
  }

  int count_;
};

int main() {
  int n = 4;

  Solution S;
  vector<vector<string>> results = S.solveNQueens(n);
  cout << S.totalNQueens(n) << endl;

  Solution2 S2;
  cout << S2.totalNQueens(n) << endl;

  return 0;
}
