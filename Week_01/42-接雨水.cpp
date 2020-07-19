
//������Ŀ����ϵ��----�ڿ��˹ٷ�����д���Ĵ��루���һ��Ǳ����ķ�����û�����������ôȥ����=��= ORZ��
//����ˮ
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int len = height.size();
        for(int i = 1;i < len;i++ ){
            int max_r = 0, max_l = 0;
            for(int l = i;l >= 0;l--){
                max_l = max(max_l, height[l]);
            }
            for(int r = i;r < len;r++){
                max_r = max(max_r, height[r]);
            }
            res += min(max_l, max_r) - height[i]; //���� ����ĳ� res = res + min(max_l, max_r) - height[i]; �ͳ�ʱ��=��=�����Ժ���Ҫ���� += ���� = +
        }
        return res;
    }
};
//��ѧϰ��ջ��˼·~~������˼· д��һ�飨�����˺þá��������⣩
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk; 
        int water = 0;
        for(int i = 0;i < height.size();i++){
            while(!stk.empty() && height[i] > height[stk.top()]){
                int ibottom = stk.top();
                stk.pop();
                while(!stk.empty() && height[stk.top()] == height[ibottom]) stk.pop();
                if(stk.empty()) break;
                int depth = min(height[stk.top()],height[i]) - height[ibottom];   
                water += (i - stk.top() - 1) * depth; 
            }
            stk.push(i);
        }
        return water;
    }
};

//����˫ָ���dp˼·����δ�������ѱ�ǡ������ύwork����ٿ�~
