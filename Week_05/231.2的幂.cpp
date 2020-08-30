/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return  n > 0&&(n&(n - 1)) == 0;
    }
};
// @lc code=end
//直接参考超哥推荐  n&(n-1)打掉 最后一位 1看看是否为0
//有个小错误！！注意一点：  == 优先级要高于 &！所以n&(n-1)要加括号
