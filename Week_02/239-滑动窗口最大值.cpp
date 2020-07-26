//˫�˶��� 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   //��¼ nums�����ֵ��Ӧ�����
        vector<int> res; //��¼ ���ֵ
        for(auto i = 0;i < nums.size();i++){
            if(!dq.empty() && dq.front()< i-k+1) dq.pop_front(); //��ǰ���ԵԪ���Ƿ����ƶ����У����ھ�ɾ��
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();//ɾ��С�ڼ����½�Ԫ�ص�ԭ��Ԫ��
            dq.push_back(i);//���浱ǰ����Ԫ�ص�����
            if(i >= k - 1) res.push_back(nums[dq.front()]);//�������ƶ�������Ԫ�� ���� res
        }
        return res;

    }
    };


    //��⣡��