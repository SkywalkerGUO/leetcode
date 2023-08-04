/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> a(cost.size() + 1);
        a[0] = 0;
        a[1] = 0;
        for (int i =2; i<cost.size()+1; i++) {
            a[i] = min(cost[i-1]+a[i-1], cost[i-2]+a[i-2]);
        }
        return a[cost.size()];
    }
};
// @lc code=end

