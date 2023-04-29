/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int start = 0;
        int end = 0;
        int loop = 0;
        if (s.size() >= 2*k){

            for (int i = 0; (2*i+2)*k<=s.size(); i++){
                start = i*2*k;
                end = (2*i+1)*k - 1;
                loop ++;
                s =reverse(s,start,end);
            }
            if (s.size() - (2*loop)*k < k) {
                start = (2*loop)*k;
                end = s.size()-1;
                s =reverse(s,start, end);
            }

            else if (s.size() - (2*loop)*k >= k) {
                start = (2*loop)*k;
                end = start+k-1;
                s =reverse(s,start,end);
            }
        }

        else if (s.size()< k) {
            start = 0;
            end = s.size()-1;
            s =reverse(s,start, end);
        }

        else  {
            start = 0;
            end = k-1;
            s = reverse(s,start,end);
        }

        
        return s;
    }

    string reverse(string s, int start, int end){
        for (int p1 = start, p2 = end; p1<=(start+end)/2; p1++, p2--){
            char temp;
            temp = s[p1];
            s[p1] = s[p2];
            s[p2] = temp;
        }
        return s;
    }
};
// @lc code=end

