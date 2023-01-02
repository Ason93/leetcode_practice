#include <iostream>
using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int j = 0;
    for (int i = 0; i < t.length() && j < s.length(); ++i) {
      if (t[i] == s[j]) {
        j++;
      }
    }
    return j == s.length();
  }
};

int main() {
  Solution S;
  string s = "abc";
  string t = "ahbgdc";
  cout << S.isSubsequence(s, t) << endl;

  s = "axc";
  t = "ahbgdc";
  cout << S.isSubsequence(s, t) << endl;

  return 0;
}