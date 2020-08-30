    /*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        //vector<vector<bool>> dp(s.size(), vector<bool> (s.size(), false));
        bool dp[1000][1000]={false};
        int res = 0;
        for(int j = 0;j < s.size();j++){
            for(int i = 0;i <= j; i++){
                if(s[i] == s[j]&& (j - i < 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
//参考大佬思想：
//dp[i][j] :字符串s在[i,j]区间的子串是否是一个回文串。
//dp[i][j]=true:
//当 s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]) 
//当只有一个字符时，比如 a 自然是一个回文串。
//当有两个字符时，如果是相等的，比如 aa，也是一个回文串。
//当有三个及以上字符时，比如 ababa 这个字符记作串 1，把两边的 a 去掉，也就是 bab 记作串 2，可以看出只要串2是一个回文串，那么左右各多了一个 a 的串 1 必定也是回文串。所以当 s[i]==s[j] 时，自然要看 dp[i+1][j-1] 是不是一个回文串。


