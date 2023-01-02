/*****************************************************
https://leetcode.com/problems/binary-tree-level-order-traversal/?envType=study-plan&id=level-1
*****************************************************/

#include <iostream>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
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
  // method DFS
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> level_order;
    _dfs(root, 0, level_order);
    return level_order;
  }

private:
  void _dfs(TreeNode *node, int level, vector<vector<int>> &level_order) {
    if (node == nullptr) {
      return;
    }
    if (level_order.size() < level + 1) {
      level_order.emplace_back(vector<int>({}));
    }
    level_order[level].emplace_back(node->val);
    _dfs(node->left, level + 1, level_order);
    _dfs(node->right, level + 1, level_order);
  }
};

int main() { return 0; }