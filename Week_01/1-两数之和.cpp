
//积累题目经验系列----暴力暴力先来一波。。。就是练练熟练度
//两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        for(int i = 0;i < nums.size()- 1;i++){
            for(int j = i + 1;j < nums.size();j++){
                if(nums[i] + nums[j] == target){
                    res[0] = i;
                    res[1] = j;
                    break;
                }
            }
        }
        return res; 
    }
};

//更重要的还是学习 哈希表~~~参考大佬思路。。。对C++ 一些哈希用法还未完全熟练（默念五毒神掌！！！）
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> hash;

        for(int i = 0; i < nums.size(); i++)
            hash[nums[i]] = i;         
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(hash.find(target-nums[i]) != hash.end() && hash[target-nums[i]] != i) 
                return {i, hash[target-nums[i]]};
        }
        return {};
    }
};


