/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int right = 0, left = 0;
        int res = 0;
        while (right< s.size()){
            char c = s[right];
            right++;
            map[c]++;
            while(map[c]>1){
                char d = s[left];
                left++;
                map[d]--;
            }
            res = max(res,right - left);
        }
        return res;
    }
};
// @lc code=end

