#include <iostream>

using namespace std;

/*****************************************************************
70. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*****************************************************************/

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
};

int main() {
  Solution S;

  int n = 2;
  cout << S.climbStairs(n) << endl;

  n = 3;
  cout << S.climbStairs(n) << endl;

  return 0;
}
