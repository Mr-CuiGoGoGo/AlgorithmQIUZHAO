
//�ο�����̳̣���ͨ���׶�
//С����
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> cnt;
        vector<int> res;

        for(auto num : nums) cnt[num]++;//�����ϣ��

        for(auto p : cnt){
            pq.push({p.second, p.first}); //�� Ƶ�� Ϊ����������
            while(pq.size() > k) pq.pop();//С�����н�����k ��Ԫ�أ��߳�ȥ�Ķ���Ƶ��С�ģ�
        } 
        while(!pq.empty()){
            res.push_back(pq.top().second);  
            pq.pop();
        }
        return res;
    }
};

//��΢�Ľ�������˼·���õĴ����
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, less<pair<int, int>>> pq;
        unordered_map<int, int> cnt;
        vector<int> res;

        for(auto num : nums) cnt[num]++;//�����ϣ��

        for(auto p : cnt){
            pq.push({p.second, p.first}); //�� Ƶ�� Ϊ����������
            //while(pq.size() > k) pq.pop();//С�����н�����k ��Ԫ�أ��߳�ȥ�Ķ���Ƶ��С�ģ�
        } 
        while(k--){
            res.push_back(pq.top().second);  
            pq.pop();
        }
        return res;
    }
};