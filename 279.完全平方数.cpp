/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for (int i = 0; i<=sqrt(n); i++){
            for (int j = i*i; j<=n; j++){
                if (dp[j-i*i]!= INT_MAX) {
                    dp[j] = min(dp[j], dp[j-i*i]+1);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

