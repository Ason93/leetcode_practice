/*****************************************************
https://leetcode.com/problems/divide-two-integers/
*****************************************************/

#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    } else if (dividend == INT_MIN && divisor == 1) {
      return INT_MIN;
    } else {
      int ans = trunc(dividend / divisor);
      return ans;
    }
  }
};

int main() {
  Solution S;
  int devidend = 10, devisor = 3;
  cout << S.divide(devidend, devisor) << endl; // 3

  devidend = 7;
  devisor = -3;
  cout << S.divide(devidend, devisor) << endl; // -2

  return 0;
}