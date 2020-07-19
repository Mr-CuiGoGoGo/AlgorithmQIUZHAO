
//������Ŀ����ϵ��----������������һ����������������������
//����֮��
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

//����Ҫ�Ļ���ѧϰ ��ϣ��~~~�ο�����˼·��������C++ һЩ��ϣ�÷���δ��ȫ������Ĭ���嶾���ƣ�������
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


