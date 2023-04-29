/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int getsum(int n) {
        int sum = 0;
        while (n){
            sum += pow(n%10,2);
            n /= 10;
        }
        return sum;
        
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while (1) {
            int sum = getsum(n);
            if (sum == 1){
                return true;
            }
            if (set.find(sum) != set.end()) {
                return false;
            }
            else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};
// @lc code=end

