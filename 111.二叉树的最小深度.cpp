/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftdepth = minDepth(root->left);
        int rightdepth = minDepth(root->right);
        if (root->left == NULL && root->right != NULL) {
            return rightdepth + 1;
        }
        if (root->right == NULL && root->left != NULL){
            return leftdepth + 1;
        }
        int res = min(leftdepth, rightdepth)+1;

        return res;
    }
};
// @lc code=end

