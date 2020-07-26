//双端队列 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   //记录 nums中最大值对应的序号
        vector<int> res; //记录 最大值
        for(auto i = 0;i < nums.size();i++){
            if(!dq.empty() && dq.front()< i-k+1) dq.pop_front(); //当前最边缘元素是否处于移动框中，不在就删除
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();//删除小于即将新进元素的原有元素
            dq.push_back(i);//保存当前新入元素的索引
            if(i >= k - 1) res.push_back(nums[dq.front()]);//将该轮移动后的最大元素 放入 res
        }
        return res;

    }
    };


    //理解！！