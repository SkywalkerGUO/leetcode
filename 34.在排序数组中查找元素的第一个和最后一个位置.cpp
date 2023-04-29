/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftbound = getleftbound(nums, target);
        int rightbound = getrightbound(nums, target);
        if (leftbound == -2 ||rightbound == -2){
            return {-1,-1};
        }
        if (rightbound - leftbound > 1) return {leftbound+1, rightbound-1};

        return {-1, -1};
    }

private:
    int getleftbound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int leftbound = -2;
        int mid = 0;
        while(left<=right){
            mid = left + (right - left)/2;
            if (nums[mid]>=target){
                right = mid - 1;
                leftbound = right;
            }
            else if (nums[mid]<target){
                left = mid + 1;
            }
        }
        return leftbound;
    }

    int getrightbound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int rightbound = -2;
        int mid = 0;
        while(left<=right){
            mid = left + (right - left)/2;
            if (nums[mid]>target){
                right = mid - 1;
            }
            else if (nums[mid]<=target){
                left = mid + 1;
                rightbound = left;
            }
        }
        return rightbound;
    }

};
// @lc code=end

