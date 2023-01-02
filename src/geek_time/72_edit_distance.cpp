#include <iostream>
#include <vector>

using namespace std;

/*****************************************************
Given two strings word1 and word2, return the minimum number of operations
required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*****************************************************/

class Solution {
public:
  int minDistance(string word1, string word2) {
    const int len1 = word1.size();
    const int len2 = word2.size();
    vector<vector<int>> distance(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; ++i) {
      distance[i][0] = i;
    }
    for (int j = 0; j <= len2; ++j) {
      distance[0][j] = j;
    }
    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        int step = word1[i - 1] == word2[j - 1] ? 0 : 1;
        distance[i][j] =
            min(min(distance[i - 1][j - 1] + step, distance[i - 1][j] + 1),
                distance[i][j - 1] + 1);
      }
    }
    return distance[len1][len2];
  }
};

int main() {
  Solution S;

  string word1 = "intention";
  string word2 = "execution";
  cout << S.minDistance(word1, word2) << endl;

  return 0;
}