
//参考超哥教程！！通俗易懂
//小根堆
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> cnt;
        vector<int> res;

        for(auto num : nums) cnt[num]++;//构造哈希表

        for(auto p : cnt){
            pq.push({p.second, p.first}); //以 频率 为堆排序依据
            while(pq.size() > k) pq.pop();//小顶堆中仅保留k 个元素（踢出去的都是频率小的）
        } 
        while(!pq.empty()){
            res.push_back(pq.top().second);  
            pq.pop();
        }
        return res;
    }
};

//稍微改进了上述思路，用的大根堆
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, less<pair<int, int>>> pq;
        unordered_map<int, int> cnt;
        vector<int> res;

        for(auto num : nums) cnt[num]++;//构造哈希表

        for(auto p : cnt){
            pq.push({p.second, p.first}); //以 频率 为堆排序依据
            //while(pq.size() > k) pq.pop();//小顶堆中仅保留k 个元素（踢出去的都是频率小的）
        } 
        while(k--){
            res.push_back(pq.top().second);  
            pq.pop();
        }
        return res;
    }
};