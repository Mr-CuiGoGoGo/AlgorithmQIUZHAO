
//ע��������Ŀ����ϵ��----�ڿ��˹ٷ����ͳ���𰸺��д���Ĵ�����΢�Ż����£�5min��Щ��=��=��
//����֮��
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums.size() < 3|| nums[0] > 0)  return {};//�����������
        for(int i = 0;i < nums.size()-2&&nums[i] <= 0;i++){  //����num[i]>0�����ֱ�ӿ���break
            if(i > 0&&nums[i] == nums[i-1]) continue;//ȥ�� �ظ�target    target= a+b = -c
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
                    while(l < r&&nums[l] == nums[l+1]) l++; //ȥ��a��b�ظ����
                    while(l < r&&nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
            }
        }
        return res;  
    }
};

//����Ҳ����˫ָ�����Ŀ�������뵽��,�������û��˼·�ˡ���Ҫѧ�ᳬ����ظ������⣨���Ƿֽ����⣩���Լ�����ȱ���һ�ֵ��������=��=
//�����Ŀ����������й�ϣ˼·���񣬵ȿ���γ������ɵ���
//�Ż���Ҫ��һЩ�ж������ļ��룬�����������ֱ��continue����break�����⣬����ʱ��һЩ���������ܻ�ȡ������Ϣ




