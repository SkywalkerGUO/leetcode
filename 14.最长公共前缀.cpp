/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = strs.size();
        // 以第一行的列数为基准
        int n = strs[0].size();
        for (int col = 0; col < n; col++) {
            for (int row = 1; row < m; row++) {
                string thisStr = strs[row], prevStr = strs[row - 1];
                // 判断每个字符串的 col 索引是否都相同
                if (col >= thisStr.size() || col >= prevStr.size() ||
                        thisStr[col] != prevStr[col]) {
                    // 发现不匹配的字符，只有 strs[row][0..col-1] 是公共前缀
                    return strs[row].substr(0, col);
                }
            }
        }
        return strs[0];
    }
};
// @lc code=end

