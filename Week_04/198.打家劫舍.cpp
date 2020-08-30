/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size();i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
// @lc code=end
//dp[i]: 0..i 能偷到最大的金额
//dp[i] = max(dp[i-2]+nums[i], dp[i-1]+0);
//i = 0 dp[0] = nums[0];
//i = 1 dp[1] = max(nums[0], nums[1]);

