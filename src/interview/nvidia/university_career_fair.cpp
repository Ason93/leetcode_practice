#include <iostream>
#include <list>
#include <vector>

using namespace std;
/***************************************************
https://leetcode.com/discuss/interview-question/374846/Twitter-or-OA-2019-or-University-Career-Fair
***************************************************/

// pair<int,int>pa[100];
// int cmp(pair<int,int>a,pair<int,int>b){
//     if(a.first!=b.first)return a.first>b.first;
//     else return a.second<b.second;
// }
// sort(pa,pa+5,cmp);

int maxEvents(vector<int> arrival, vector<int> duration) {
  list<vector<int>> l;
  for (int i = 0; i < arrival.size(); ++i) {
    vector<int> x;
    x.push_back(arrival[i]);
    x.push_back(duration[i]);
    l.push_back(x);
  }
  l.sort(
      [](vector<int> a, vector<int> b) { return a[1] + a[0] < b[1] + b[0]; });
  int max_Events = 0, end = 0;
  for (auto i : l) {
    cout << i[0] << i[1] << endl;
    if (i[0] >= end) {
      ++max_Events;
      end = i[0] + i[1];
    }
  }

  return max_Events;
}

int main() {
  vector<int> arrival = {1, 3, 3, 5, 7};
  vector<int> duration = {2, 2, 1, 2, 1};
  cout << maxEvents(arrival, duration) << endl;
  return 0;
}