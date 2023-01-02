/*****************************************************
https://leetcode.com/problems/longest-common-prefix/
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string s = strs[0];
    int n = s.length();
    for (int i = 0; i < strs.size(); ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[j] != strs[i][j]) {
          s = s.substr(0, j);
          break;
        }
      }
    }
    return s;
  }
};

int main() {
  Solution S1;
  vector<string> str1 = {"flower", "flow", "flight"};
  cout << S1.longestCommonPrefix(str1) << endl; // "fl"

  Solution S2;
  vector<string> str2 = {"dog", "racear", "car"};
  cout << S2.longestCommonPrefix(str2) << endl; // ""

  return 0;
}