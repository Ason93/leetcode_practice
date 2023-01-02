#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*******************************************************************************************
https://leetcode.com/discuss/interview-question/1236641/online-assessment-startup-india-hard
*******************************************************************************************/

unordered_set<int> findCycle(vector<vector<int>> &g, int &g_nodes) {
  unordered_set<int> se;
  unordered_map<int, int> d;
  for (int i = 0; i < g_nodes; ++i) {
    d[i] = g[i].size();
  }
  vector<int> visited(g_nodes, 0);
  queue<int> q;
  for (int i = 0; i < g_nodes; ++i) {
    if (d[i] <= 1) {
      q.push(i);
      visited[i] = 1;
    }
  }

  while (!q.empty()) {
    int front = q.front();
    q.pop();
    for (int i = 0; i < g[front].size(); ++i) {
      d[g[front][i]]--;
      if (visited[g[front][i]] == 0 && d[g[front][i]] == 1) {
        visited[g[front][i]] = 1;
        q.push(g[front][i]);
      }
    }
  }

  for (int i = 0; i < g_nodes; ++i) {
    if (visited[i] == 0) {
      se.insert(i);
    }
  }

  return se;
}

int shortPath(vector<vector<int>> &g, int &g_nodes, int &x,
              unordered_set<int> &se) {
  queue<pair<int, int>> q;
  vector<int> visited(g_nodes, 0);
  q.push({x, 0});
  visited[x] = 1;
  int ans = INT_MAX;
  while (!q.empty()) {
    auto [front, level] = q.front();
    q.pop();
    for (int i = 0; i < g[front].size(); ++i) {
      if (se.find(g[front][i]) != se.end()) {
        return level + 1;
      } else if (visited[g[front][i]] == 0) {
        visited[g[front][i]] = 1;
        q.push({g[front][i], level + 1});
      }
    }
  }
  return ans;
}

vector<int> nodeDistance(int g_nodes, vector<int> g_from, vector<int> g_to) {
  vector<vector<int>> g(g_nodes);
  for (int i = 0; i < g_nodes; ++i) {
    g[g_from[i] - 1].push_back(g_to[i] - 1);
    g[g_to[i] - 1].push_back(g_from[i] - 1);
  }
  unordered_set<int> se = findCycle(g, g_nodes);

  vector<int> ans(g_nodes, 0);
  for (int i = 0; i < g_nodes; ++i) {
    if (se.find(i) != se.end()) {
      // cout << i << endl;
      continue;
    }
    ans[i] = shortPath(g, g_nodes, i, se);
  }
  return ans;
}

int main() {

  int g_nodes = 6;
  vector<int> g_from = {1, 2, 1, 3, 1, 2};
  vector<int> g_to = {2, 3, 3, 5, 4, 6};

  vector<int> res = nodeDistance(g_nodes, g_from, g_to);
  for (auto r : res) {
    cout << r << ", ";
  }
  cout << endl;

  return 0;
}
