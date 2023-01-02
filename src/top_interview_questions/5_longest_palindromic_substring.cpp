/*****************************************************
https://leetcode.com/problems/longest-palindromic-substring/
*****************************************************/

#include <iostream>

using namespace std;
// O(N^2)
class Solution {
public:
  Solution() : maxLen_(0) {}

  string longestPalindrome(string s) {
    if (s.size() <= 1) {
      return s;
    }
    for (int i = 0; i < s.size() - 1; ++i) {
      findLongestPalindrome(s, i, i);
      findLongestPalindrome(s, i, i + 1);
    }
    return subs_;
  }

  void findLongestPalindrome(string s, int low, int high) {
    while (low >= 0 && high <= s.size() - 1) {
      if (s[low] == s[high]) {
        if (high - low + 1 > maxLen_) {
          maxLen_ = high - low + 1;
          subs_ = s.substr(low, high - low + 1);
        }
        low--;
        high++;
      } else {
        break;
      }
    }
  }

private:
  int maxLen_;
  string subs_;
};

int main() {
  Solution S1;
  string s1 = "babad";
  cout << S1.longestPalindrome(s1) << endl; // bab

  Solution S2;
  string s2 = "cbbd";
  cout << S2.longestPalindrome(s2) << endl; // bb
  return 0;
}