/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = size(nums);
        TreeNode* root = new TreeNode(nums[(l-1)/2]);
        TreeNode* cur = root;
        int left = (l-1)/2 - 1;
        int right = (l-1)/2 + 1;

        while (left>= 0) {
            cur->left = new TreeNode(nums[left]);
            left--;
            cur = cur->left;
        }
        TreeNode* cur2 = root;
        while (right<=l){
            cur2->right = new TreeNode(nums[right]);
            right++;
            cur2 = cur2->right;
        }

        return root;
    }
};


/* class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + ((right - left) / 2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
}; */
// @lc code=end

