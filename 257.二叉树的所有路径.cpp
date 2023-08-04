/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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

    void construct(TreeNode* root, string path, vector<string>& paths) {
        if (root != NULL) {
            path += to_string(root->val);
        }
        if (root->left ==NULL && root->right == NULL) {
            paths.push_back(path);
        }
        else {
            path += "->";
            if (root->left) construct(root->left, path, paths);
            if (root->right) construct(root->right, path, paths);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        construct(root, "", paths);
        return paths;
    }
};
// @lc code=end

