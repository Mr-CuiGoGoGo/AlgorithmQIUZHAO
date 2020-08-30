/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> sum(triangle);
        for(int i = triangle.size()-2;i >= 0; i--){
            for(int j = 0;j < triangle[i].size();j++){
                sum[i][j] = min(sum[i+1][j], sum[i+1][j+1])+sum[i][j];
            }
        }
        return sum[0][0];
    }
};
// @lc code=end
// 子问题： sum[i, j] = min(sum[i+1,j] ,sum[i+1,j+1]) + num[i,j]; 
//sum[i,j] 第 i 层 第 j 个元素为顶 的 下三角最小路径和
