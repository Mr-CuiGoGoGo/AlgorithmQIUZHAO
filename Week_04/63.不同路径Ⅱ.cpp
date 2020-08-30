/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;//搞定初始化第1行和第1列为1~~
        for(int i = 1;i <= m;i++){
            for(int j = 1; j <= n;j++){
                if(obstacleGrid[i-1][j-1] == 0)
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
//在不同路径基础上添加下判断即可