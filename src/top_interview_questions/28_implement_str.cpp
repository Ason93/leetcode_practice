/*****************************************************
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
*****************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    const int n = haystack.size();
    const int m = needle.size();
    for (int i = 0; i < n - m + 1; ++i) {
      string sub = haystack.substr(i, m);
      if (sub == needle) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution S;
  string haystack = "hello", needle = "ll";
  cout << S.strStr(haystack, needle) << endl; // 2

  haystack = "aaaaa";
  needle = "bba";
  cout << S.strStr(haystack, needle) << endl; // -1

  haystack = "sadbutsad";
  needle = "sad";
  cout << S.strStr(haystack, needle) << endl; // 0

  haystack = "leetcode";
  needle = "leeto";
  cout << S.strStr(haystack, needle) << endl; // -1
  return 0;
}