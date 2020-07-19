
//注：积累题目经验系列----在看了官方题解和超哥答案后才写出的代码（5min有些短=。=）
//盛水最多的容器
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //双指针
        int len = nums.size();
        int j = 0;
        for(int i = 0;i < len;i++) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                if(i != j) {
                    nums[i] = 0;    
                }
                j++;
            }
        }
    }
};

//还是类似双指针的题目。分别指向待测数组中不同位置，这类思想要有
//此外，国外大佬有个滚雪球的代码时间效率要更高一些（从起初的0元素不停的滚，遇0则滚、并！交换元素位置）
//C++中algorithm中现成函数swap、max、min =。=以前不知道还有这么方便的函数。（看了官方题解C++才知道）
/

