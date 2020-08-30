/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

//默写
// @lc code=end
//1. 子问题
// 1) s1[n] == s2[m]  lcs[s1,s2] = lcs[s1-1, s2-1]+1
// 2) s1[n] !=  s2[m]  lcs[s1,s2] = max(lcs[s1-1,s2],lcs[s1,s2-1])
//
//      "  a  b  c  d  e    
//  "   1  1  1  1  1  1 
//  a   1  1  1  1  1  1
//  c   1
//  e   1
//