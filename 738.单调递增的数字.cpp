/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = std::to_string(n);
        string result;
        int index = s.size();
        for (int i = s.size()-1; i>0; i--) {
            if (s[i]<s[i-1]) {
                s[i-1]--;
                index = i;
            }
        }
        for (int i = index; i<s.size(); i++){
            s[i] =  '9';
        }
        return stoi(s);
    }
};
// @lc code=end

