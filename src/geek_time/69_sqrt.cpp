#include <iostream>

using namespace std;

/***************************************
69. Sqrt(x)
Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only
the integer part of the result is returned. Note: You are not allowed to use any
built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Example 1:
Input: x = 4
Output: 2

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is
truncated, 2 is returned.
***************************************/

class Solution {
public:
  // method binary search
  int mySqrt(int x) {
    if (x < 2) {
      return x;
    }
    int left = 1;
    int right = x / 2;
    while (left <= right) {
      const int mid = (left + right) / 2;
      if (mid > x / mid) { // warn: large num
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left - 1;
  }

  // method newton iteration
  int mySqrt2(int x) {
    if (x < 2) {
      return x;
    }
    int r = x;
    while (r * r > x) {
      r = r / 2 + (x / r) / 2;
    }
    return r;
  }
};

int main() {
  Solution S;

  int x = 4;
  cout << S.mySqrt(x) << endl;
  cout << S.mySqrt2(x) << endl;

  x = 3;
  cout << S.mySqrt(x) << endl;
  cout << S.mySqrt2(x) << endl;

  x = 5;
  cout << S.mySqrt(x) << endl;
  cout << S.mySqrt2(x) << endl;

  x = 6;
  cout << S.mySqrt(x) << endl;
  cout << S.mySqrt2(x) << endl;

  x = 7;
  cout << S.mySqrt(x) << endl;
  cout << S.mySqrt2(x) << endl;

  x = 8;
  cout << S.mySqrt(x) << endl;
  cout << S.mySqrt2(x) << endl;

  x = 9;
  cout << S.mySqrt(x) << endl;
  cout << S.mySqrt2(x) << endl;

  return 0;
}