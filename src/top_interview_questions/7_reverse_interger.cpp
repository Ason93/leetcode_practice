/*****************************************************
https://leetcode.com/problems/reverse-integer/
*****************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    int64_t tmp = x;
    int64_t res = 0;
    tmp = tmp < 0 ? -tmp : tmp;
    while (tmp) {
      res = res * 10 + tmp % 10;
      tmp /= 10;
    }
    if (res < INT_MIN || res > INT_MAX) {
      return 0;
    }
    return x < 0 ? -res : res;
  }
};

int main() {
  Solution S;

  int x = 123;
  cout << S.reverse(x) << endl; // 321

  x = -123;
  cout << S.reverse(x) << endl; // -321

  x = 120;
  cout << S.reverse(x) << endl; // 21

  return 0;
}