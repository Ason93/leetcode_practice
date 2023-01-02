/******************************************************************************
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid. An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
******************************************************************************/

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    // time: O(n)
    // space: O(n)
    unordered_map<char, char> parentheses = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };
    stack<char> st;
    for (auto c : s) {
      if (parentheses.count(c) == 0) { // right bracket
        if (st.empty() ||
            parentheses[st.top()] !=
                c) { // first one is right bracket or not match, false
          return false;
        }
        st.pop();
      } else { // left bracket
        st.emplace(c);
      }
    }
    return st.empty();
  }
};

int main() {
  Solution S;

  string s = "()";
  bool is_valid = S.isValid(s);
  cout << "Valid parentheses flag in true case is: " << is_valid << endl;

  s = "()[]";
  is_valid = S.isValid(s);
  cout << "Valid parentheses flag in true case is: " << is_valid << endl;

  s = "([)]";
  is_valid = S.isValid(s);
  cout << "Valid parentheses flag in false case is: " << is_valid << endl;

  s = "((([]))";
  is_valid = S.isValid(s);
  cout << "Valid parentheses flag in false case is: " << is_valid << endl;

  s = "]][[";
  is_valid = S.isValid(s);
  cout << "Valid parentheses flag in false case is: " << is_valid << endl;

  return 0;
}
