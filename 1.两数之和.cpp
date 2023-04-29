/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for (int i=0;i<nums.size();i++) {
            auto index = umap.find(target-nums[i]);
            if (index != umap.end()) return {index->second, i};
            else umap.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};
// @lc code=end

