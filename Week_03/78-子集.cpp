class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        if(nums.empty()) return ans;
        dfs(ans, nums, vec, 0);
        return ans;
    }
    void dfs(vector<vector<int>> &ans, vector<int> nums, vector<int> vec, int index){
        //terminator
        if(index == nums.size()){
            ans.push_back(vec);
            return;
        }
        //process
        dfs(ans, nums, vec, index + 1); // not pick the number at this index
        vec.push_back(nums[index]);
        dfs(ans, nums, vec, index + 1); // pick the number at this index
        //reverse state(restore state)


    }
};
//参考超哥java思路...更加理解了C++和java不一致。此处，dfs传入参数vec没有&。所以不需要 reverse
//如下则需要：
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        if(nums.empty()) return ans;
        dfs(ans, nums, vec, 0);
        return ans;
    }
    void dfs(vector<vector<int>> &ans, vector<int> nums, vector<int> &vec, int index){
        //terminator
        if(index == nums.size()){
            ans.push_back(vec);
            return;
        }
        //process
        dfs(ans, nums, vec, index + 1); // not pick the number at this index
        vec.push_back(nums[index]);
        dfs(ans, nums, vec, index + 1); // pick the number at this index
        //reverse state(restore state)
        vec.pop_back();

    }
};
//上述两种都是可以通过的。就是参考 n个格子选还是不选，时间复杂度为O（n）


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > ans;
        ans.push_back({vector<int>{}});//空的，作为[[]]是最初状态
        //cout<< ans.size() <<endl;
        vector<int> temp;

        //枚举nums的每个元素，加到ans的每个元素里面
        for(int i=0;i<nums.size();++i)
        {
            int sz=ans.size();
            for(int j=0;j<sz;++j)
            {
                temp=ans[j];//然后往temp里面加元素nums[i]
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
//解释如下：
//例如，{1,2,3}最初有一个空集作为结果[[]]
/*
考虑1，如果不使用它，仍然[]，如果使用1，则将其添加到[]，所以我们有[1]现在
合并它们，现在我们有[[]，[1]]作为所有可能的子集

接下来考虑2，如果不使用它，我们仍然有[[]，[1]]，如果使用2，只需将2添加到每个先前的子集，我们就有[2]，[1,2]
合并它们，现在我们有了[[]，[1]，[2]，[1,2]]

接下来考虑3，如果不使用它，我们仍然有[[]，[1]，[2]，[1,2]]，如果使用3，只需将3添加到每个先前的子集，我们就有[[3]， [1,3]，[2,3]，[1,2,3]]
合并它们，现在我们有[[]，[1]，[2]，[1,2]，[3]，[1 ，3]，[2,3]，[1,2,3]]
*/