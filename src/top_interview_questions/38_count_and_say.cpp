/*****************************************************
https://leetcode.com/problems/count-and-say/
*****************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string input = "1";
    for (int i = 0; i < n - 1; ++i) {
      string str;
      int count = 0;
      char num = input[0];
      for (int id = 0; id < input.size(); id++) {
        if (input[id] == num) {
          count++;
        } else {
          str += (to_string(count) + num);
          count = 1;
          num = input[id];
        }
        if (id == input.size() - 1) {
          str += (to_string(count) + num);
          input = str;
          break;
        }
      }
    }
    return input;
  }
};

int main() {
  Solution S;
  int n = 1;
  cout << S.countAndSay(n) << endl; // 1

  n = 4;
  cout << S.countAndSay(n) << endl; // 1211

  return 0;
}