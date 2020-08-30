/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i = 1;i <= m;i++) dp[i][1] = dp[i-1][1] + grid[i-1][0];
        for(int i = 1;i <= n;i++) dp[1][i] = dp[1][i-1] + grid[0][i-1];
        for(int i = 2;i <= m;i++){
            for(int j = 2;j <= n;j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
// 子问题: problem(i,j) = min(problem(i-1,j) , problem(i,j-1));
// dp[i, j]: 到达第 i,j 处最小的数字总和
//dp[i, j] = min(dp[i-1,j] , dp[i, j-1]) + grid[i,j];
