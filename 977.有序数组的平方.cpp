/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int leftindex = 0, rightindex = nums.size()-1;
        vector<int> result(nums.size(),0);
        int k = rightindex;
        for (leftindex=0; leftindex<=rightindex;){
            if (nums[leftindex]*nums[leftindex] < nums[rightindex]*nums[rightindex]){
                result[k--] = nums[rightindex]*nums[rightindex];
                rightindex--;

            }
            else {
                result[k--] = nums[leftindex]*nums[leftindex];
                leftindex++;
            }
        }
        return result;
    }
};
// @lc code=end

