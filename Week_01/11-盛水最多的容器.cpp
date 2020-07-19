
//注：在下菜鸡一枚，在看了官方题解后才写出的代码
//盛水最多的容器
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int area = 0;
        int cur_area = 0;
        //双指针
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
//尝试过暴力求解O(n^2)，时间超时=。=
//改进;自运算符可以合并进表达式~~