/*****************************************************
https://leetcode.com/problems/rotate-image/
*****************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // method1: o(n^2), space o(0)
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    // transposing the matrix
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    // reversing each row of the matrix
    for (int i = 0; i < n; i++) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }

  // method2: o(n^2), space o(n^2)
  void rotate2(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return;
    }
    int n = matrix.size(); // shape(matrix) = n*n
    vector<vector<int>> tmp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      int id = 0;
      for (int j = n - 1; j >= 0; --j) {
        tmp[i][id] = matrix[j][i];
        id++;
      }
    }
    matrix = tmp;
  }
};

int main() {
  Solution S;
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  S.rotate(matrix); // {{7,4,1},{8,5,2},{9,6,3}}

  matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  S.rotate(matrix); // {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}

  return 0;
}