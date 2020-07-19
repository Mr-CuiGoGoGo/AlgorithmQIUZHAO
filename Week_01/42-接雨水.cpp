
//积累题目经验系列----在看了官方题解才写出的代码（而且还是暴力的方法都没想出来。。怎么去暴力=。= ORZ）
//接雨水
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int len = height.size();
        for(int i = 1;i < len;i++ ){
            int max_r = 0, max_l = 0;
            for(int l = i;l >= 0;l--){
                max_l = max(max_l, height[l]);
            }
            for(int r = i;r < len;r++){
                max_r = max(max_r, height[r]);
            }
            res += min(max_l, max_r) - height[i]; //这里 如果改成 res = res + min(max_l, max_r) - height[i]; 就超时了=。=。。以后看来要多用 += 代替 = +
        }
        return res;
    }
};
//还学习了栈的思路~~。照着思路 写了一遍（调试了好久。。找问题）
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk; 
        int water = 0;
        for(int i = 0;i < height.size();i++){
            while(!stk.empty() && height[i] > height[stk.top()]){
                int ibottom = stk.top();
                stk.pop();
                while(!stk.empty() && height[stk.top()] == height[ibottom]) stk.pop();
                if(stk.empty()) break;
                int depth = min(height[stk.top()],height[i]) - height[ibottom];   
                water += (i - stk.top() - 1) * depth; 
            }
            stk.push(i);
        }
        return water;
    }
};

//还有双指针和dp思路，还未看。。已标记。。等提交work后就再看~
