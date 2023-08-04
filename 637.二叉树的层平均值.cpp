/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        if (root!=NULL) que.push(root);
        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i<size; i++){
                TreeNode* node = que.front();
                que.pop();

                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }   
            result.push_back(vec);
        }
        vector<double> avgvec;
        for (vector<int> vec1 : result){
            double sum = 0.0;
            for (int j = 0; j< vec1.size(); j++){
                sum += vec1[j];
            }
            double avg = sum/vec1.size();
            avgvec.push_back(avg);
        }
        return avgvec;
    }
};
// @lc code=end

