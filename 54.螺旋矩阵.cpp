/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int upperbound = 0, lowerbound = m-1;
        int leftbound = 0, rightbound = n-1;
        vector <int> res;

        while (res.size()<m*n){
            if (upperbound<=lowerbound){
                for (int i=leftbound; i<=rightbound; i++){
                    res.push_back(matrix[upperbound][i]);
                }
                upperbound++;
            }

            if (leftbound<=rightbound){
                for (int j=upperbound; j<=lowerbound; j++){
                    res.push_back(matrix[j][rightbound]);
                }
                rightbound--;
            }
            if (upperbound<=lowerbound){
                for (int i=rightbound; i>=leftbound; i--){
                    res.push_back(matrix[lowerbound][i]);
                }
                lowerbound--;
            }
            if (leftbound<=rightbound){
                for (int j=lowerbound; j>=upperbound; j--){
                    res.push_back(matrix[j][leftbound]);
                }
                leftbound++;
            }
        }
        return res;

    }
};

// @lc code=end

