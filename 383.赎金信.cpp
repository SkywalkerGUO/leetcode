/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        if (ransomNote.size()>magazine.size()){
            return false;
        }
        else {
            for (int j = 0; j<magazine.size();j++){
                record[magazine[j]-'a']++;
            }
            for (int i = 0; i<ransomNote.size(); i++){
                record[ransomNote[i]-'a'] --;
                if (record[ransomNote[i]-'a']<0) return false;
            }
        }
        return true;
    }
};
// @lc code=end

