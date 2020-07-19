
//注：积累题目经验系列----在看了官方题解和超哥答案后才写出的代码稍微优化了下（5min有些短=。=）
//三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums.size() < 3|| nums[0] > 0)  return {};//考虑特殊情况
        for(int i = 0;i < nums.size()-2&&nums[i] <= 0;i++){  //考虑num[i]>0的情况直接可以break
            if(i > 0&&nums[i] == nums[i-1]) continue;//去除 重复target    target= a+b = -c
            int l = i + 1, r = nums.size() - 1, target = 0 - nums[i]; 
            while(l < r){
                if(nums[l] + nums[r] > target){
                    r--;
                }
                else if(nums[l] + nums[r] < target){
                    l++;
                }
                else{
                    res.push_back({nums[i],nums[l],nums[r]});
                    while(l < r&&nums[l] == nums[l+1]) l++; //去除a和b重复情况
                    while(l < r&&nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
            }
        }
        return res;  
    }
};

//还是也类似双指针的题目。排序想到了,但后面就没有思路了。。要学会超哥的重复子问题（或是分解问题），自己总是缺灵光一现的那种灵感=。=
//这个题目解决起来还有哈希思路好像，等看完课程再来干掉！
//优化主要是一些判断条件的加入，比如特殊情况直接continue或是break；此外，遍历时加一些条件尽可能获取有用信息




