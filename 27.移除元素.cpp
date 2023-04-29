/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowindex = 0, fastindex = 0;
        for (fastindex=0; fastindex < nums.size(); fastindex++){
            if (val!=nums[fastindex]){
                nums[slowindex++] = nums[fastindex];
            }
        }
        return slowindex;
    }
};
// @lc code=end

