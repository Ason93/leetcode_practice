/*****************************************************
https://leetcode.com/problems/running-sum-of-1d-array/
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          count++;
          dfs(grid, visited, i, j);
        }
      }
    }
    return count;
  }

private:
  void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int sr,
           int sc) {
    if (sr < 0 || sr >= grid.size() || sc < 0 || sc >= grid[0].size() ||
        visited[sr][sc] == true || grid[sr][sc] == '0') {
      return;
    }
    visited[sr][sc] = true;
    vector<int> mr = {-1, 1, 0, 0};
    vector<int> mc = {0, 0, -1, 1};
    for (int i = 0; i < mr.size(); ++i) {
      dfs(grid, visited, sr + mr[i], sc + mc[i]);
    }
  }
  int count = 0;
};

int main() {
  Solution S1;

  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};

  cout << S1.numIslands(grid) << endl; // 1

  Solution S2;
  grid = {{'1', '1', '0', '0', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '1', '0', '0'},
          {'0', '0', '0', '1', '1'}};
  cout << S2.numIslands(grid) << endl; // 3

  return 0;
}