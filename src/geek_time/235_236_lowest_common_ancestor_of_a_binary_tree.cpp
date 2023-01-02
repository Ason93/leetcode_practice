#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/***********************************
235. Lowest Common Ancestor of a Binary Search Tree
Given a binary search tree (BST),
find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest
node in T that has both p and q as descendants (where we allow a node to be a
descendant of itself).”
***********************************/

class Solution {
public:
  // method non-recursion: O(n)
  TreeNode *lowestCommonAncestor1(TreeNode *root, TreeNode *p, TreeNode *q) {
    while (root) {
      if (root->val < p->val && root->val < q->val) {
        root = root->right;
      } else if (root->val > p->val && root->val > q->val) {
        root = root->left;
      } else {
        break;
      }
    }
    return root;
  }

  // method recursion: O(n)
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root->val < p->val && root->val < q->val) {
      return lowestCommonAncestor(root->right, p, q);
    }
    if (root->val > p->val && root->val > q->val) {
      return lowestCommonAncestor(root->left, p, q);
    }
    return root;
  }
};

/***********************************
236. Lowest Common Ancestor of a Binary Tree
Given a binary tree,
find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest
node in T that has both p and q as descendants (where we allow a node to be a
descendant of itself).”
***********************************/

class Solution2 {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    return left == nullptr ? right : right == nullptr ? left : root;
  }
};

int main() { return 0; }
