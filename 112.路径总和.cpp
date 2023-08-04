/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    void pathsum(TreeNode* root, int sum, vector<int> &sums) {
        if (root->left == NULL && root->right == NULL) {
            sums.push_back(sum);
            return;
        }
        if (root->left){
            sum += root->left->val;
            pathsum(root->left, sum, sums);
            sum -= root->left->val;
        }
            
        if (root->right){
            sum += root->right->val;
            pathsum(root->right, sum, sums);
            sum -= root->right->val;
        }
            
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        vector<int> sums;
        std::vector<int>::iterator it;
        pathsum(root, root->val, sums);
        it = find(sums.begin(), sums.end(), targetSum);
        if (it == sums.end()) return false;

        else return true;
    }
};
// @lc code=end

