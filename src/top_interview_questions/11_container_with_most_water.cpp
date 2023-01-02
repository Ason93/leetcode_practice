/*****************************************************
https://leetcode.com/problems/container-with-most-water/
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int max_area = INT_MIN;
    int begin = 0;
    int end = height.size() - 1;
    while (begin < end) {
      int area = INT_MIN;
      if (height[begin] < height[end]) {
        area = height[begin] * (end - begin);
        begin++;
      } else {
        area = height[end] * (end - begin);
        end--;
      }
      max_area = max(area, max_area);
    }
    return max_area;
  }
};

int main() {
  Solution S1;
  vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << S1.maxArea(height1) << endl; // 49

  Solution S2;
  vector<int> height2 = {1, 1};
  cout << S2.maxArea(height2) << endl; // 1

  return 0;
}