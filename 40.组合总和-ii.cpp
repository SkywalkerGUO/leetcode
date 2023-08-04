/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int sum, int startidx){
        if (sum == target){
            result.push_back(path);
            return;
        }
        if (sum > target) return;
        for (int i = startidx; i<candidates.size(); i++){
            if (i > startidx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i+1);
            sum -= candidates[i];
            path.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end

