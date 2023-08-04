/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        for (string str: strs) {
            int onenum = 0, zeronum = 0;
            for (auto c:str) {
                if (c=='0') zeronum++;
                else onenum++;
            }
            for (int i = m; i>=zeronum; i--){
                for (int j = n; j>=onenum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-zeronum][j-onenum]+1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

