/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for(int i = 0;i < 32;i++){
            //res = ((n&1)<<(31-i)) + res;//一开始前面没加括号，一直错。。
            res += (n&1)<<(31-i);
            n = n >> 1;
            
        }
        return res;
    }
};
// @lc code=end

//运算符号的优先级一定要注意，位运算<<不如正常的+ -。。。。我说一直找不到原因