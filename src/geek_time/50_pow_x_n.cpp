/**************************************
50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
**************************************/

#include <iostream>

using namespace std;

class Solution {
public:
  // method recursion: O(logn)
  double myPow(double x, int n) {
    if (n == 0) {
      return 1.0;
    }
    if (n < 0) {
      return 1 /
             myPow(x,
                   -n); // warn: when n=INT_MAX, -n will be out of range of int
    }
    if (n % 2 == 1) {
      return x * myPow(x, n - 1);
    }
    return myPow(x * x, n / 2);
  }

  // method non-recursion: O(logn)
  double myPow2(double x, int n) {
    if (n < 0) {
      x = 1 / x;
      n = -n; // warn: when n=INT_MAX, -n will be out of range of int
    }
    double pow = 1.0;
    while (n) {
      if (n & 1) {
        pow *= x;
      }
      x *= x;
      n >>= 1;
    }
    return pow;
  }

  // method recursion: O(logn)
  double myPow3(double x, int n) {
    if (n == 0) {
      return 1.0;
    }
    if (n < 0 && n % 2 == -1) {
      return myPow(x, n + 1) / x;
    }
    if (n > 0 && n % 2 == 1) {
      return myPow(x, n - 1) * x;
    }
    return myPow(x * x, n / 2);
  }

  // method non-recursion: O(logn)
  double myPow4(double x, int n) {
    double y = x;
    int count = n;
    double pow = 1.0;
    while (count) {
      if (count % 2 != 0) {
        pow *= y;
      }
      y *= y;
      count /= 2;
    }
    return n < 0 ? 1 / pow : pow;
  }
};

int main() {

  Solution S;

  double x = 2.0;
  int n = 10;
  cout << S.myPow(x, n) << endl;
  cout << S.myPow2(x, n) << endl;
  cout << S.myPow3(x, n) << endl;
  cout << S.myPow4(x, n) << endl;

  x = 2.1;
  n = 3;
  cout << S.myPow(x, n) << endl;
  cout << S.myPow2(x, n) << endl;
  cout << S.myPow3(x, n) << endl;
  cout << S.myPow4(x, n) << endl;

  x = 2.0;
  n = -2;
  cout << S.myPow(x, n) << endl;
  cout << S.myPow2(x, n) << endl;
  cout << S.myPow3(x, n) << endl;
  cout << S.myPow4(x, n) << endl;

  return 0;
}
