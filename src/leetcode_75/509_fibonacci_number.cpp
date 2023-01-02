/*****************************************************
https://leetcode.com/problems/fibonacci-number/?envType=study-plan&id=level-1
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int fib(int n) {
    if (n == 0 || n == 1) {
      return n;
    }
    return fib(n - 1) + fib(n - 2);
  }

  int fib2(int n) {
    if (n == 0 || n == 1) {
      return n;
    }
    int a = 0;
    int b = 1;
    int sum = 0;
    for (int i = 1; i < n; ++i) {
      sum = a + b;
      a = b;
      b = sum;
    }
    return sum;
  }
};

int main() {
  Solution S;

  int n = 2;
  cout << S.fib(n) << endl;  // 1
  cout << S.fib2(n) << endl; // 1

  n = 3;
  cout << S.fib(n) << endl;  // 2
  cout << S.fib2(n) << endl; // 2

  n = 4;
  cout << S.fib(n) << endl;  // 3
  cout << S.fib2(n) << endl; // 3

  n = 5;
  cout << S.fib(n) << endl;  // 5
  cout << S.fib2(n) << endl; // 5

  return 0;
}