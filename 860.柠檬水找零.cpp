/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num[2]={0}; //5 10 20
        if(bills[0]!= 5) return false;
        for (int i = 0; i<bills.size(); i++) {
            if (bills[i]==5) num[0]++;
            else if (bills[i]==10) {
                num[1]++;
                num[0]--;
            }
            else {
                if (num[1]>0) {
                    num[1]--;
                    num[0]--;
                }
                else num[0]-=3;
            }

            if (num[0]<0||num[1]<0) return false;
        }
        return true;
    }
};
// @lc code=end

