/*****************************************************
https://leetcode.com/problems/validate-binary-search-tree/?envType=study-plan&id=level-1
*****************************************************/

#include <iostream>
#include <vector>

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
  bool isValidBST(TreeNode *root) { return isValid(root, LONG_MIN, LONG_MAX); }

private:
  bool isValid(TreeNode *node, int64_t min_value, int64_t max_value) {
    if (node == nullptr) {
      return true;
    }
    if (node->val <= min_value || node->val >= max_value) {
      return false;
    }
    return isValid(node->left, min_value, node->val) &&
           isValid(node->right, node->val, max_value);
  }
};

int main() { return 0; }