#include <iostream>

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
  /****************************************
  104. Maximum Depth of Binary Tree
  Given the root of a binary tree, return its maximum depth.
  A binary tree's maximum depth is the number of nodes along
  the longest path from the root node down to the farthest leaf node.
  ****************************************/

  int maxDepth(TreeNode *root) {
    return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
  }

  /****************************************
      111. Minimum Depth of Binary Tree
      Given a binary tree, find its minimum depth.
      The minimum depth is the number of nodes along the shortest path
      from the root node down to the nearest leaf node.
      Note: A leaf is a node with no children.
  ****************************************/

  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    if (!root->left) {
      return 1 + minDepth(root->right);
    }
    if (!root->right) {
      return 1 + minDepth(root->left);
    }

    // devide and conquer
    int leftMinDepth = minDepth(root->left);
    int rightMinDepth = minDepth(root->right);

    // process subproblems' results
    int result = 1 + min(leftMinDepth, rightMinDepth);

    return result;
  }
};

int main() { return 0; }
