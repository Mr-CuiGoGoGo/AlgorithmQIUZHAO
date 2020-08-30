/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;//搞定初始化第1行和第1列为1~~
        for(int i = 1;i <= m;i++){
            for(int j = 1; j <= n;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
// 向下或者向右-> op[i][j] = op[i][j-1] + op[i-1][j]
// dp[i][j]: 达到第i，j的格子可能的走法 
// 
