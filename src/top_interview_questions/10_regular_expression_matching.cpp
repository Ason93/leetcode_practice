/*****************************************************
https://leetcode.com/problems/regular-expression-matching/
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    // i --> s, j --> p
    // 1. dp[i][j] = dp[i-1][j-1] && (p[j] == '.' || s[i] == p[j]), if p[j] != *
    // 2. dp[i][j] = dp[i][j-2], if p[j] == '*' and preceding char matches 0
    // times
    // 3. dp[i][j] = dp[i-1][j] && (s[i] == p[j-1] || p[j-1] == '.')  if p[j] ==
    // '*' and preceding char matches at least once

    s = '0' + s;
    p = '0' + p;
    int sz = s.size() - 1;
    int pz = p.size() - 1;
    vector<vector<bool>> dp(sz + 1, vector<bool>(pz + 1, false));
    dp[0][0] = true;

    // Case 2 base case when s = "0"
    // s = ''
    // p = 'ab*'
    for (int j = 2; j <= pz; j++) {
      if (p[j] == '*')
        dp[0][j] = dp[0][j - 2];
    }

    for (int i = 1; i <= sz; i++) {
      for (int j = 1; j <= pz; j++) {
        if (p[j] != '*') {
          // Case 1:
          dp[i][j] = dp[i - 1][j - 1] && (p[j] == '.' || s[i] == p[j]);
        } else {
          // Case 2,3:
          dp[i][j] = dp[i][j - 2] ||
                     (dp[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
        }
      }
    }
    return dp[sz][pz];
  }
};

int main() {
  Solution S1;
  string s1 = "aa", p1 = "a";
  cout << S1.isMatch(s1, p1) << endl; // false

  Solution S2;
  string s2 = "aa", p2 = "a*";
  cout << S2.isMatch(s2, p2) << endl; // true

  Solution S3;
  string s3 = "ab", p3 = ".*";
  cout << S3.isMatch(s3, p3) << endl; // true

  Solution S4;
  string s4 = "aab", p4 = "c*a*b";
  cout << S4.isMatch(s4, p4) << endl; // true

  return 0;
}