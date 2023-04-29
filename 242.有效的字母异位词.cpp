/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26]={0};
        int pointer = 0;
        for (int i=0; i<s.size(); i++){
            pointer = s[i]-'a';
            record[pointer]++;
        }
        for (int j = 0; j<t.size(); j++){
            pointer = t[j]-'a';
            record[pointer]--;
        }
        for (int k = 0; k<26; k++){
            if (record[k]!=0) return false;
            else continue; 
        }
        return true;
    }
};
// @lc code=end

