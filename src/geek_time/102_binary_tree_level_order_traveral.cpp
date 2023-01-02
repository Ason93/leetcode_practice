/******************************
102. Binary Tree Level Order Traversal
Given the root of a binary tree,
return the level order traversal of its nodes' values.
(i.e., from left to right, level by level).
******************************/

#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  // method BFS
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }
    queue<TreeNode *> que;
    que.emplace(root);
    vector<vector<int>> results;
    while (!que.empty()) {
      vector<int> result;
      int level_size = que.size();
      for (int i = 0; i < level_size; ++i) {
        TreeNode *node = que.front();
        result.emplace_back(node->val);
        que.pop();
        if (node->left) {
          que.emplace(node->left);
        }
        if (node->right) {
          que.emplace(node->right);
        }
      }
      results.emplace_back(result);
    }
    return results;
  }

  // method DFS
  vector<vector<int>> levelOrder2(TreeNode *root) {
    if (!root) {
      return {};
    }
    _dfs(root, 0);
    return _results;
  }

  void _dfs(TreeNode *node, int level) {
    if (!node) {
      return;
    }

    if (_results.size() < level + 1)
      _results.emplace_back(vector<int>{});

    _results[level].emplace_back(node->val);

    _dfs(node->left, level + 1);
    _dfs(node->right, level + 1);
  }

  vector<vector<int>> _results;
};

int main() { return 0; }
