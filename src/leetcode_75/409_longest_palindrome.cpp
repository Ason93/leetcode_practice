/*****************************************************
https://leetcode.com/problems/longest-palindrome/
*****************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> char_map;
    int len = 0;
    for (auto c : s) {
      char_map[c]++;
      if (char_map[c] == 2) {
        char_map[c] = 0;
        len += 2;
      }
    }
    for (auto c : s) {
      if (char_map[c] == 1) {
        len++;
        break;
      }
    }
    return len;
  }
};

int main() {
  Solution S;

  string s = "abccccdd";
  cout << S.longestPalindrome(s) << endl; // 7

  s = "a";
  cout << S.longestPalindrome(s) << endl; // 1

  return 0;
}