/*****************************************************
https://leetcode.com/problems/first-bad-version/?envType=study-plan&id=level-1
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version) { return true; }; // fake function

class Solution {
public:
  int firstBadVersion(int n) {
    int64_t low = 1;
    int64_t high = n;
    int result = 0;
    while (low <= high) {
      int64_t mid = (low + high) / 2;
      if (isBadVersion(mid)) {
        result = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return result;
  }
};

int main() {
  Solution S;

  int n = 5;                            // bad = 4
  cout << S.firstBadVersion(n) << endl; // 4

  n = 1;                                // bad = 1
  cout << S.firstBadVersion(n) << endl; // 1

  return 0;
}