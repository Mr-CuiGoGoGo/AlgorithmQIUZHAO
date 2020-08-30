/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int max_side = 0;
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                dp[i][j] = matrix[i-1][j-1] =='1'? min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1 : 0;
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side*max_side;
    }
};
//当然以上代码可以 只创建 m * n的dp，这样的话遍历时应单独判断第一行和第一列的dp应该与matrix[i][j]相等~~
//这样是为了dp公式形式统一在边界条件
// @lc code=end
//虽知道是用dp 但不放在这一章节，根本想不到用dp。。。也不知如何dp
//=。=我真滴想不到。。！！ 子问题： dp[i,j]=min(dp[i-1,j],dp[i,j-1],dp[i-1,j-1])+1
//状态定义： dp[i,j] 表示以[i,j]为右下角，且只包含1的正方形的边长最大值。
//边界条件：若i和j至少有一个为0，则d[i,j] = 1；在边上了指定为最大为1，若元素本身为0那就是0了 
//关键推导：
//https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/solution/tong-ji-quan-wei-1-de-zheng-fang-xing-zi-ju-zhen-2/

