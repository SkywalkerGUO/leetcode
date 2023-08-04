/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left>=right) return NULL;
        int maxindex = left;
        for (int i = left+1; i<right; i++){
            if(nums[i]>nums[maxindex]) maxindex = i;
        }

        TreeNode* root = new TreeNode(nums[maxindex]);
        
        root->left = traversal(nums, left, maxindex);
        root->right = traversal(nums, maxindex+1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
// @lc code=end

