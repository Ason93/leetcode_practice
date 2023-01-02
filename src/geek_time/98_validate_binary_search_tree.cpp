/*********************************
98. Validate Binary Search Tree
Given the root of a binary tree, determine if it is a valid binary search tree
(BST). A valid BST is defined as follows: The left subtree of a node contains
only nodes with keys less than the node's key. The right subtree of a node
contains only nodes with keys greater than the node's key. Both the left and
right subtrees must also be binary search trees.
*********************************/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <iostream>
using namespace std;

// method middle search: O(n)

// method recursion: O(n)
class Solution {
public:
  bool isValidBST(TreeNode *root) { return isValid(root, -LONG_MAX, LONG_MAX); }

private:
  bool isValid(TreeNode *root, int64_t min_value, int64_t max_value) {
    if (root == nullptr) {
      return true;
    }
    if (root->val < min_value || root->val > max_value) {
      return false;
    }
    return isValid(root->left, min_value, root->val) &&
           isValid(root->right, root->val, max_value);
  }
};

int main() { return 0; }
