/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1;i <= amount; i++){
            for(int j = 0;j < coins.size();j++){
                if(i >= coins[j]){
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1) ;
                }
            }
        }
        return amount < dp[amount]? -1 : dp[amount];
    }
};
// @lc code=end
//子问题： f[i] =min( f[i-coin1] , f[i-coin2] , f[i-coin3]...) + 1;
//        f[i] = min( f[i-coins[j]] for(j) ) + 1;
//为啥不是简单的相加，因为爬楼梯的话是求各种不同的方式，要累加
//改题目要求出 是 最少，最少，最少，相当于这么多方式中最少的那个是多少
//coins 为各种面值的硬币
//f[i] ： 凑出 金额 i 所需要的最少的硬币个数 
