/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum(nums.size());
        int res = nums[0];
        sum[0] = nums[0];
        for(int i=1;i < nums.size();i++){
            sum[i] = max(sum[i-1]+nums[i],nums[i]);
            res = max(res, sum[i]);
        }
        return res;
    }
};
// @lc code=end
//子问题（重复性）： max（i） = max(max(i-1) + num[i], num[i]); 
//说白了就是判断 前 i-1 个最大连续子序列和（包含第 i-1个元素） 是否 > 0,  否则就去掉！
//dp 和 贪心思路差不多
//定义状态： sum[i] 包含的第 i个元素的前 i 个 最大连续子序列和 
//sum[i] = max(sum[i-1]+num[i], num[i]);
//or  sum[i] = max(sum[i-1], 0)+ num[i]; 
