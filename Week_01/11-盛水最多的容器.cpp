
//ע�����²˼�һö���ڿ��˹ٷ������д���Ĵ���
//ʢˮ��������
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int area = 0;
        int cur_area = 0;
        //˫ָ��
        while(left < right){
            if(height[left] > height[right]){
                cur_area = height[right] * (right - left); 
                right--;
            }
            else{
                cur_area = height[left] * (right - left);
                left++;
            }
            if(cur_area > area){
                area = cur_area;
            }
        }
        return area;
    }
};
//���Թ��������O(n^2)��ʱ�䳬ʱ=��=
//�Ľ�;����������Ժϲ������ʽ~~