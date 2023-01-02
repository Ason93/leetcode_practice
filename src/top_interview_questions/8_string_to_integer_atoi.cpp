/*****************************************************
https://leetcode.com/problems/string-to-integer-atoi/
*****************************************************/

#include <climits>
#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    int start = 0;
    bool sign = true;
    int64_t ans = 0;
    while (s[start] == ' ') {
      start++;
    }
    if (s[start] == '-') {
      sign = false;
      start++;
    } else if (s[start] == '+') {
      start++;
    }
    for (int i = start; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        ans = ans * 10 + s[i] - '0';
        if (ans > INT_MAX && sign) {
          return ans = INT_MAX;
        } else if (-ans < INT_MIN && !sign) {
          return ans = INT_MIN;
        }
      } else {
        break;
      }
    }
    if (sign) {
      return ans;
    } else {
      return -ans;
    }
  }
};

int main() {
  Solution S1;
  string s1 = "42";
  cout << S1.myAtoi(s1) << endl; // 42

  Solution S2;
  string s2 = "   -42";
  cout << S2.myAtoi(s2) << endl; // -42

  Solution S3;
  string s3 = "4193 with words";
  cout << S3.myAtoi(s3) << endl; // 4193

  Solution S4;
  string s4 = "+1";
  cout << S4.myAtoi(s4) << endl; // 1

  return 0;
}