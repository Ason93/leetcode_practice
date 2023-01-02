/*****************************************************
https://leetcode.com/problems/permutations/
*****************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // dfs, O(n^2)
  void dfs(const int n, const vector<int> &nums, vector<bool> &visited,
           vector<int> &tmp, vector<vector<int>> &ans) {
    if (tmp.size() == n) {
      ans.emplace_back(tmp);
      return;
    }
    for (int j = 0; j < n; ++j) {
      if (visited[j]) {
        continue;
      }
      tmp.emplace_back(nums[j]);
      visited[j] = true;
      dfs(n, nums, visited, tmp, ans);
      tmp.pop_back();
      visited[j] = false;
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    const int n = nums.size();
    vector<bool> visited(n, false);
    vector<int> tmp;
    vector<vector<int>> ans;
    dfs(n, nums, visited, tmp, ans);
    return ans;
  }
  // std
  vector<vector<int>> permute2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> permutations;
    do {
      permutations.emplace_back(nums.cbegin(), nums.cend());
    } while (next_permutation(nums.begin(), nums.end()));
    return permutations;
  }
};

int main() {
  Solution S;
  vector<int> nums = {1, 3, 2};
  S.permute(nums); // [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

  nums = {0, 1};
  S.permute(nums); // [[0,1],[1,0]]

  nums = {1};
  S.permute(nums); // [[1]]

  return 0;
}