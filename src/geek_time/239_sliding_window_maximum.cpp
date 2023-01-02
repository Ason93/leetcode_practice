/*********************************************
239. Sliding Window Maximum
You are given an array of integers nums,
there is a sliding window of size k which is moving from the very left of the
array to the very right. You can only see the k numbers in the window. Each time
the sliding window moves right by one position. Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
*********************************************/
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
  // method queue: O(n)
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    if (nums.empty()) {
      return {};
    }
    vector<int> win_max;
    deque<int> max_idx;
    max_idx.emplace_back(0);
    for (int i = 0; i < nums.size(); ++i) {
      if (max_idx.front() <= i - k) { // reomve the element out of the window
        max_idx.pop_front();
      }
      while (!max_idx.empty() &&
             nums[max_idx.back()] <=
                 nums[i]) { // warn: "<=" -> remove the init element
        max_idx.pop_back();
      }
      max_idx.emplace_back(i);
      if (i >= k - 1) {
        win_max.emplace_back(nums[max_idx.front()]);
      }
    }
    return win_max;
  }

  // method priority_queue: O(n*log(k))
  vector<int> maxSlidingWindow2(vector<int> &nums, int k) {
    if (nums.empty()) {
      return {};
    }
    vector<int> win_max;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
        max_heap; // max heap
    for (int i = 0; i < nums.size(); ++i) {
      while (!max_heap.empty() &&
             max_heap.top().second <= i - k) { // warn: remove all old elements
        max_heap.pop();
      }
      max_heap.emplace(make_pair(nums[i], i));
      if (i >= k - 1) {
        win_max.emplace_back(max_heap.top().first);
      }
    }
    return win_max;
  }
};

int main() {
  Solution s;
  // case 1
  // vector<int> input = {1,3,-1,-3,5,3,6,7};
  // int k=3;

  // case2
  // vector<int> input = {1,-1};
  // int k=1;

  // case 3
  vector<int> input = {1, 3, 1, 2, 0, 5};
  int k = 3;

  cout << "Input:" << endl;
  for (auto i : input) {
    cout << i << ", ";
  }
  cout << endl;

  // method 1
  vector<int> output = s.maxSlidingWindow(input, k);
  cout << "Output:" << endl;
  for (auto o : output) {
    cout << o << ", ";
  }
  cout << endl;

  // method 2
  vector<int> output2 = s.maxSlidingWindow2(input, k);
  cout << "Output2:" << endl;
  for (auto o : output2) {
    cout << o << ", ";
  }
  cout << endl;

  return 0;
}
