/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    void traversal(TreeNode* cur, unordered_map<int, int>& map) {
        if (cur == NULL) return;
        map[cur->val]++;
        traversal(cur->left, map);
        traversal(cur->right, map);
        return;
    }

    bool static compare(pair<int, int> a, pair<int, int> b) {
        return a.second>b.second;
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> map;
        vector<int> result;
        if (root == NULL) return result;
        traversal(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), compare);
        result.push_back(vec[0].first);

        for (int i = 1; i<vec.size(); i++) {
            if (vec[i].second== vec[0].second) result.push_back(vec[i].first);
            else break;
        }
        return result;

    }
};
// @lc code=end

