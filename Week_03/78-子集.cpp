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
//�ο�����java˼·...���������C++��java��һ�¡��˴���dfs�������vecû��&�����Բ���Ҫ reverse
//��������Ҫ��
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
//�������ֶ��ǿ���ͨ���ġ����ǲο� n������ѡ���ǲ�ѡ��ʱ�临�Ӷ�ΪO��n��


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > ans;
        ans.push_back({vector<int>{}});//�յģ���Ϊ[[]]�����״̬
        //cout<< ans.size() <<endl;
        vector<int> temp;

        //ö��nums��ÿ��Ԫ�أ��ӵ�ans��ÿ��Ԫ������
        for(int i=0;i<nums.size();++i)
        {
            int sz=ans.size();
            for(int j=0;j<sz;++j)
            {
                temp=ans[j];//Ȼ����temp�����Ԫ��nums[i]
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
//�������£�
//���磬{1,2,3}�����һ���ռ���Ϊ���[[]]
/*
����1�������ʹ��������Ȼ[]�����ʹ��1��������ӵ�[]������������[1]����
�ϲ����ǣ�����������[[]��[1]]��Ϊ���п��ܵ��Ӽ�

����������2�������ʹ������������Ȼ��[[]��[1]]�����ʹ��2��ֻ�轫2��ӵ�ÿ����ǰ���Ӽ������Ǿ���[2]��[1,2]
�ϲ����ǣ�������������[[]��[1]��[2]��[1,2]]

����������3�������ʹ������������Ȼ��[[]��[1]��[2]��[1,2]]�����ʹ��3��ֻ�轫3��ӵ�ÿ����ǰ���Ӽ������Ǿ���[[3]�� [1,3]��[2,3]��[1,2,3]]
�ϲ����ǣ�����������[[]��[1]��[2]��[1,2]��[3]��[1 ��3]��[2,3]��[1,2,3]]
*/