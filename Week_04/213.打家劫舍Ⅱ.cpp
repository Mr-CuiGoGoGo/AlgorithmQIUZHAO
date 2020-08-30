/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!nums.size()) return 0;
        if(nums.size() == 1) return nums[0];
        return max(myrob(nums, 0, n-2), myrob(nums, 1, n-1));
    }
    int myrob(vector<int> nums, int start, int end){
        vector<int> dp(nums.size(), 0);
        dp[0] = 0;
        dp[1] = nums[start]; 
        for(int i = 2;i <= nums.size()-1;i++){
            dp[i] = max(dp[i-2]+ nums[start+i-1], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
// @lc code=end
//在 打家劫舍I 基础上 增添了 第 0个仓库 和 第 n-1个不能同时抢劫的限制
//故可 转化为在 0 ~ n-2 仓库和  1 ~ n-1 仓库分别求打家劫舍 I 的问题
//两者取最大~即可
//仓库编号：0 ~ n-1
// dp[i] i个仓库可以偷的最大值 包括仓库数为0的情况，所以 0~n-2 仓库为n-1个，dp为n大小
