/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
//这里的背包容量就是target，sum/2，背包容量为target的背包，能背的最大石头重量
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i< stones.size(); i++) {
            sum += stones[i];
        }
        vector<int> dp(15001, 0);
        int target = sum/2;
        for (int i = 0; i<stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        return sum - 2*dp[target];
    }
};
// @lc code=end

