/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void traversal(TreeNode* cur, vector<int>& node){
        if (cur==NULL) return;
        traversal(cur->left, node);
        node.push_back(cur->val);
        traversal(cur->right, node);

    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> node;
        traversal(root, node);
        return node;
    }
};
// @lc code=end

