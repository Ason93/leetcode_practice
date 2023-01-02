/*****************************************************
https://leetcode.com/problems/roman-to-integer/
*****************************************************/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (i < s.size() - 1 && roman_map[s[i + 1]] > roman_map[s[i]]) {
        num += roman_map[s[i + 1]] - roman_map[s[i]];
        i++;
      } else {
        num += roman_map[s[i]];
      }
    }
    return num;
  }
  unordered_map<char, int> roman_map = {{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};
};

int main() {
  Solution S1;
  string s1 = "III";
  cout << S1.romanToInt(s1) << endl; // 3, III = 3.

  Solution S2;
  string s2 = "LVIII";
  cout << S2.romanToInt(s2) << endl; // 58, L = 50, V= 5, III = 3.

  Solution S3;
  string s3 = "MCMXCIV";
  cout << S3.romanToInt(s3)
       << endl; // 1994, M = 1000, CM = 900, XC = 90 and IV = 4.

  return 0;
}