#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

// O(n^2*log(n))
struct Combine {
  int arr1_e;
  int arr2_e;
  int sum_e;
  Combine(int a1, int a2) : arr1_e(a1), arr2_e(a2) { sum_e = arr1_e + arr2_e; }
};

bool operator<(Combine a, Combine b) { return a.sum_e < b.sum_e; }

class Solution {
public:
  vector<vector<int>> kthMaxSum(vector<int> &arr1, vector<int> &arr2, int K) {
    assert(arr1.size() == arr2.size());
    const int N = arr1.size();

    priority_queue<Combine> combines; // default: greater, max heap
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        Combine combine(arr1[i], arr2[j]);
        combines.push(combine);
      }
    }
    vector<vector<int>> res;
    for (int i = 0; i < K; ++i) {
      Combine tmp = combines.top();
      res.emplace_back(vector<int>{tmp.arr1_e, tmp.arr2_e, tmp.sum_e});
      cout << "arr1: " << tmp.arr1_e << ", arr2: " << tmp.arr2_e
           << ", sum: " << tmp.sum_e << endl;
      combines.pop();
    }
    return res;
  }
};

// O(n*log(n))
class Solution2 {
public:
  vector<vector<int>> kthMaxSum(vector<int> &arr1, vector<int> &arr2, int K) {
    assert(arr1.size() == arr2.size());
    vector<int> arr1_tmp = arr1;
    sort(arr1_tmp.begin(), arr1_tmp.end(), greater<int>());
    vector<int> arr2_tmp = arr2;
    sort(arr2_tmp.begin(), arr2_tmp.end(), greater<int>());
    priority_queue<pair<int, pair<int, int>>>
        combines; // default: greater, max heap
    set<pair<int, int>> combines_idx;
    combines.push(make_pair(arr1_tmp[0] + arr2_tmp[0], make_pair(0, 0)));
    combines_idx.insert(make_pair(0, 0));
    vector<vector<int>> res;
    for (int k = 0; k < K; ++k) {
      pair<int, pair<int, int>> combine = combines.top();
      combines.pop();
      const int i = combine.second.first;
      const int j = combine.second.second;
      res.emplace_back(vector<int>{arr1_tmp[i], arr2_tmp[j], combine.first});
      cout << "arr1: " << arr1_tmp[i] << ", arr2: " << arr2_tmp[j]
           << ", sum: " << combine.first << endl;
      int tmp1_sum = arr1_tmp[i + 1] + arr2_tmp[j];
      pair<int, int> tmp1_idx = make_pair(i + 1, j);
      if (combines_idx.find(tmp1_idx) == combines_idx.end()) {
        combines.push(make_pair(tmp1_sum, tmp1_idx));
        combines_idx.insert(tmp1_idx);
      }
      int tmp2_sum = arr1_tmp[i] + arr2_tmp[j + 1];
      pair<int, int> tmp2_idx = make_pair(i, j + 1);
      if (combines_idx.find(tmp2_idx) == combines_idx.end()) {
        combines.push(make_pair(tmp2_sum, tmp2_idx));
        combines_idx.insert(tmp2_idx);
      }
    }
    return res;
  }
};

int main() {
  vector<int> arr1 = {9, 3, 5, 7, 3};
  vector<int> arr2 = {5, 8, 1, 4, 5};
  const int K = 3;
  cout << "######## method 1: " << endl;
  Solution S;
  vector<vector<int>> res = S.kthMaxSum(arr1, arr2, K);
  cout << "######## method 2: " << endl;
  Solution2 S2;
  vector<vector<int>> res2 = S2.kthMaxSum(arr1, arr2, K);
  return 0;
}