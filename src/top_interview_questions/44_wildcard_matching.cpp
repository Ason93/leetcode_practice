/*****************************************************
https://leetcode.com/problems/wildcard-matching/
*****************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// tabulation(submits well)
class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.length();
    int m = p.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    // base cases
    dp[0][0] = true; // both lengths are over
    for (int i = 1; i <= m; i++) {
      if (p[i - 1] == '*')
        dp[i][0] = true; // continuous * from start are true only
      else
        break;
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
          dp[i][j] = dp[i - 1][j - 1];
        else if (p[i - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        else
          dp[i][j] = false;
      }
    }
    return dp[m][n];
  }
};

int main() {
  Solution S;
  string s = "aa", p = "a";
  cout << S.isMatch(s, p) << endl; // false

  s = "aa";
  p = "*";
  cout << S.isMatch(s, p) << endl; // true

  s = "cb";
  p = "?a";
  cout << S.isMatch(s, p) << endl; // false

  s = "adceb";
  p = "*a*b";
  cout << S.isMatch(s, p) << endl; // true

  return 0;
}