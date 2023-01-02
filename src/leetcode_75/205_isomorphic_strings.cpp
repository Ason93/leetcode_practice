/*****************************************************
https://leetcode.com/problems/isomorphic-strings/
*****************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

/*****************************************************
python
One-liner:
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        return len(set(s)) == len(set(t)) == len(set(zip(s, t)))
*****************************************************/

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<int, int> mapping_s;
    unordered_map<int, int> mapping_t;
    for (int i = 0; i < s.length(); ++i) {
      if (mapping_s.count(s[i]) == 0 && mapping_t.count(t[i]) == 0) {
        mapping_s[s[i]] = t[i];
        mapping_t[t[i]] = s[i];
      } else if (mapping_s[s[i]] != t[i] || mapping_t[t[i]] != s[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution S;
  string s = "egg";
  string t = "add";
  cout << S.isIsomorphic(s, t) << endl;

  s = "foo";
  t = "bar";
  cout << S.isIsomorphic(s, t) << endl;

  s = "paper";
  t = "title";
  cout << S.isIsomorphic(s, t) << endl;

  return 0;
}