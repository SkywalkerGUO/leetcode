/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int height(TreeNode* node){
        if (node == NULL) {
            return 0;
        }
        int leftHeight = height(node->left); // 左
        if (leftHeight == -1) return -1;
        int rightHeight = height(node->right); // 右
        if (rightHeight == -1) return -1;

        int result;
        if (abs(leftHeight - rightHeight) > 1) {  // 中
            result = -1;
        } 
        else {
            result = 1 + max(leftHeight, rightHeight); // 以当前节点为根节点的树的最大高度
        }

        return result;
    }

    bool isBalanced(TreeNode* root) {
        return height(root)==-1 ? false : true;
    }
};
// @lc code=end

