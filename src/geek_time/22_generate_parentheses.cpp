#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**********************************
22. Generate Parentheses
Given n pairs of parentheses,
write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: []""()()())))"",""()())()))"",""()()))())"",""())()()))"",""())())())""]

Example 2:
Input: n = 1
Output: []""())""]
**********************************/

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    _generate(0, 0, n, "");
    return _results;
  }

  void _generate(int left, int right, int n, string result) {
    if (left == n && right == n) {
      _results.emplace_back(result);
      return;
    }
    if (left < n) {
      _generate(left + 1, right, n, result + "(");
    }
    if (left > right && right < n) {
      _generate(left, right + 1, n, result + ")");
    }
  }

  vector<string> _results;
};

int main() {
  int n;
  vector<string> results;
  Solution S;

  n = 3;
  results = S.generateParenthesis(n);
  cout << "results: " << endl;
  for (auto result : results) {
    cout << result << endl;
  }

  return 0;
}
