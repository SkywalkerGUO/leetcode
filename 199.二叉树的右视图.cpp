/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    void order(TreeNode* cur, int depth, vector<vector<int>>& result){

        if (cur == NULL) return;
        if (result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, depth + 1, result);
        order(cur->right, depth + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root, depth, result);
        vector<int> right;
        for (int i=0; i<result.size(); i++){
            right.push_back(result[i].back());
        }
        return right;
    }
};
// @lc code=end

