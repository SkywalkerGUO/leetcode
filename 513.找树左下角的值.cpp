/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int maxdepth = -1;
    int result;

    void traversal(TreeNode* root, int depth) {
        if (root->left == NULL && root->right == NULL) {
            if (depth > maxdepth){
                maxdepth = depth;
                result = root->val;
            }
            return;
        }

        if(root->left){
            depth++;
            traversal(root->left, depth);
            depth--;
        }

        if(root->right){
            depth++;
            traversal(root->right, depth);
            depth--;

        }
    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};
// @lc code=end

