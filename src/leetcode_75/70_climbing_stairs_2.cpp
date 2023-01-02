/*****************************************************
https://leetcode.com/problems/climbing-stairs/
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // abstract to Fibonacci sequence: O(n), space O(1)
  int climbStairs(int n) {
    int one_step = 0;
    int two_step = 1;
    int all_step = 0;
    for (int i = 1; i <= n; ++i) {
      all_step = one_step + two_step;
      one_step = two_step;
      two_step = all_step;
    }
    return all_step;
  }

  int climbStairs2(int n) {
    if (n == 0 || n == 1) {
      return 1;
    }
    return climbStairs2(n - 1) + climbStairs2(n - 2);
  }
};

int main() {
  Solution S;

  int n = 2;
  cout << S.climbStairs(n) << endl;  // 2
  cout << S.climbStairs2(n) << endl; // 2

  n = 3;
  cout << S.climbStairs(n) << endl;  // 3
  cout << S.climbStairs2(n) << endl; // 3

  return 0;
}