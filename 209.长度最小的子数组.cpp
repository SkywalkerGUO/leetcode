/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = 0;
        int i=0,j =0;
        int sum = 0;
        int result = INT_MAX;
        for (j=0; j<nums.size(); j++){
            sum += nums[j];
            while (sum>=target){
                length = j-i+1;
                result = result < length ? result : length;
                sum -= nums[i++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};
// @lc code=end

