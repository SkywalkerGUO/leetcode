/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
                if (a[0]==b[0]) return a[1]<b[1];
                return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> queue;
        int k = 0;
        for (int i = 0; i<people.size(); i++) {
            k = people[i][1];
            queue.insert(queue.begin()+k, people[i]);
            
        }
        return queue;
    }
};
// @lc code=end

