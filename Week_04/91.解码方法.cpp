/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1; dp[1] = 1;//为了保证统一性！！
        for(int i = 2;i <= s.size();i++){
            if(s[i-1] == '0'){
                if(s[i-2] == '1'|| s[i-2] == '2') dp[i] = dp[i-2];
                else return 0;
            }
            else if(s[i-2] == '1'||(s[i-2] == '2'&&s[i-1]>='1'&&s[i-1]<='6')){
                dp[i] = dp[i-1] + dp[i-2];
            }
            else dp[i] = dp[i-1];
        }
        return dp[s.size()];
    }
};
// @lc code=end
//参考大佬思路：
//子问题： 
//1、s[i] = '0' ->   s[i-1]=1 or 2 dp[i] =dp[i-2]; return 0
//2、s[i-1] = '1'  ->  dp[i] = dp[i-1] + dp[i-2];
//3、s[i-1] = '2' && 1<=s[i]<=6 dp[i] = dp[i-1]+dp[i-2];
//状态定义 dp[i] 为str[0..i]的译码方法总数
