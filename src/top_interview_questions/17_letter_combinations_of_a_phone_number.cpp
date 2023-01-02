/*****************************************************
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*****************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  void solve(int idx, string &letter, const string &digits) {
    if (idx == digits.size()) {
      letters_.emplace_back(letter);
      return;
    }
    string value = dig2let_map_[digits[idx]];
    for (auto v : value) {
      letter.push_back(v);
      solve(idx + 1, letter, digits);
      letter.pop_back();
    }
  }

  vector<string> letterCombinations(string &digits) {
    if (digits.empty()) {
      return {};
    }
    int idx = 0;
    string letter;
    solve(idx, letter, digits);
    return letters_;
  }

private:
  unordered_map<char, string> dig2let_map_ = {
      {'0', ""},    {'1', ""},    {'2', "abc"},  {'3', "def"}, {'4', "ghi"},
      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
  vector<string> letters_;
};

int main() {
  Solution S1;
  string digits1 = "23";
  cout << "input 1: " << digits1 << endl;
  // ["ad","ae","af","bd","be","bf","cd","ce","cf"]
  vector<string> letters1 = S1.letterCombinations(digits1);
  for (auto r : letters1) {
    cout << r << endl;
  }

  Solution S2;
  string digits2 = "";
  cout << "input 2: " << digits2 << endl;
  // ""
  vector<string> letters2 = S2.letterCombinations(digits2);
  for (auto r : letters2) {
    cout << r << endl;
  }

  Solution S3;
  string digits3 = "2";
  cout << "input 3: " << digits3 << endl;
  // ["a","b","c"]
  vector<string> letters3 = S3.letterCombinations(digits3);
  for (auto r : letters3) {
    cout << r << endl;
  }

  return 0;
}