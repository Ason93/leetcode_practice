#include <iostream>
#include <vector>

using namespace std;

class Circles {
public:
  Circles(vector<vector<char>> &grid) : count_(0) {
    const int m = grid.size();
    const int n = grid[0].size();
    roots_ = vector<int>(m * n, -1);
    ranks_ = vector<int>(m * n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          roots_[i * n + j] = i * n + j;
          count_++;
        }
      }
    }
  }

  void unionCircle(int i, int j) {
    int root_i = findRoot(i);
    int root_j = findRoot(j);
    if (root_i != root_j) {
      if (ranks_[root_i] < ranks_[root_j]) {
        roots_[root_j] = root_i;
      } else if (ranks_[root_i] > ranks_[root_j]) {
        roots_[root_i] = root_j;
      } else {
        roots_[root_j] = root_i;
        ranks_[root_i] += 1;
      }
      count_--;
    }
  }

  int count() { return count_; }

private:
  int findRoot(int i) {
    int root = i;
    while (root != roots_[root]) {
      root = roots_[root];
    }
    while (i != roots_[i]) {
      int tmp = roots_[i];
      roots_[i] = root;
      i = tmp;
    }
    return root;
  }

  vector<int> roots_;
  vector<int> ranks_;
  int count_;
};

class CirclesInt {
public:
  CirclesInt(vector<vector<int>> &grid) : count_(0) {
    const int m = grid.size();
    const int n = grid[0].size();
    roots_ = vector<int>(m * n, -1);
    ranks_ = vector<int>(m * n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          roots_[i * n + j] = i * n + j;
          count_++;
        }
      }
    }
  }

  void unionCircle(int i, int j) {
    int root_i = findRoot(i);
    int root_j = findRoot(j);
    if (root_i != root_j) {
      if (ranks_[root_i] < ranks_[root_j]) {
        roots_[root_j] = root_i;
      } else if (ranks_[root_i] > ranks_[root_j]) {
        roots_[root_i] = root_j;
      } else {
        roots_[root_j] = root_i;
        ranks_[root_i] += 1;
      }
      count_--;
    }
  }

  int count() { return count_; }

private:
  int findRoot(int i) {
    int root = i;
    while (root != roots_[root]) {
      root = roots_[root];
    }
    while (i != roots_[i]) {
      int tmp = roots_[i];
      roots_[i] = root;
      i = tmp;
    }
    return root;
  }

  vector<int> roots_;
  vector<int> ranks_;
  int count_;
};

class Solution {
public:
  /****************************
  200. Number of Islands
  Given an m x n 2D binary grid grid which represents a map of '1's (land) and
  '0's (water), return the number of islands. An island is surrounded by water
  and is formed by connecting adjacent lands horizontally or vertically. You may
  assume all four edges of the grid are all surrounded by water.

  Example 1:
  Input: grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
  ]
  Output: 1

  Example 2:
  Input: grid = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
  ]
  Output: 3

  Constraints:
  m == grid.length
  n == grid[i].length
  1 <= m, n <= 300
  grid[i][j] is '0' or '1'.
  ****************************/
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    const int m = grid.size();
    const int n = grid[0].size();
    Circles circles(grid);
    vector<vector<int>> direct = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          int a_id = i * n + j;
          for (int d = 0; d < 4; ++d) {
            int nr = i + direct[d][0];
            int nc = j + direct[0][d];
            int b_id = nr * n + nc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
              circles.unionCircle(a_id, b_id);
            }
          }
        }
      }
    }
    return circles.count();
  }

  /****************************
  547. Number of Provinces
  There are n cities. Some of them are connected, while some are not. If city a
  is connected directly with city b, and city b is connected directly with city
  c, then city a is connected indirectly with city c.
  A province is a group of directly or indirectly connected cities and no other
  cities outside of the group.
  You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
  ith city and the jth city are directly connected, and isConnected[i][j] = 0
  otherwise.
  Return the total number of provinces.

  Example 1:
  Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
  Output: 2

  Example 2:
  Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
  Output: 3
  ****************************/
  int findCircleNum(vector<vector<int>> &isConnected) {
    if (isConnected.empty() || isConnected[0].empty()) {
      return 0;
    }
    const int m = isConnected.size();
    const int n = isConnected[0].size();
    CirclesInt circles(isConnected);
    vector<vector<int>> direct = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1) {
          int a_id = i * n + j;
          for (int d = 0; d < 4; ++d) {
            int nr = i + direct[d][0];
            int nc = j + direct[0][d];
            int b_id = nr * n + nc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                isConnected[nr][nc] == 1) {
              circles.unionCircle(a_id, b_id);
            }
          }
        }
      }
    }
    return circles.count();
  }
};

int main() {
  Solution S;

  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};

  cout << S.numIslands(grid) << endl;

  grid = {{'1', '1', '0', '0', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '1', '0', '0'},
          {'0', '0', '0', '1', '1'}};
  cout << S.numIslands(grid) << endl;

  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  cout << S.findCircleNum(isConnected) << endl;

  isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  cout << S.findCircleNum(isConnected) << endl;

  return 0;
}