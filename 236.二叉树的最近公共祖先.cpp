/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root==q ||root == NULL){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q); //left
        TreeNode* right = lowestCommonAncestor(root->right, p, q);  //right
        if (right != NULL && left != NULL) return root;
        else if (right == NULL && left != NULL) return left;
        else if (right != NULL && left == NULL) return right;
        else return NULL;

    }
};
// @lc code=end

