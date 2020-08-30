/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n != 0) {
            res ++;
            n = n & (n-1);
        }
        /*for(int i = 0;i < 32;i++){
            if(n&1) res++;
            n = n >> 1;
        }*/        
        return res;
    }
};
// @lc code=end
//之前没接触过位运算，0.0学习超哥思路
//1. for loop: 0->32 查看每一位
//2. %2 先看最后一位是不是1   /2 再打掉！ 继续 %2 
//3. &1 。。同上，只是位操作  x = x >> 1
//以上都是时间复杂度 32次
// x = x & (x-1)  清零最低位的 1
// while(x > 0) {count ++; x = x & (x-1);} 复杂度为 1 的个数
