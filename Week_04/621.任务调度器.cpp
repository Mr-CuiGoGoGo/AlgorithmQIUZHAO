/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int map[26]={0};
        for(auto c:tasks){
            map[c - 'A']++;
        }
        sort(map, map + 26);
        int time = 0;
        while(map[25] > 0){//任务没完成：开始一轮 
            int i = 0;
            while(i <= n){//空闲时间；；超过空闲时间就要开始下一轮了 
                if(map[25] == 0) break;
                //处理 最高类的任务，然后下次循环在处理下一种
                if(i < 26 && map[25-i] > 0) map[25-i]--;
                time++;// 无论 是否做了新的任务 或者 冷却，时间都要增加
                i++;//要处理下 次次高 个 任务
            }
            //以上执行了n次
            sort(map,map + 26);//排完序，准备下一轮
        }
        return time;
    }
};
// @lc code=end
//先模仿一波官方题解 暴力法

//模仿大佬方法
/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> vec(26);
        for(auto c:tasks) vec[c-'A']++;
        sort(vec.begin(),vec.end(),[](int & x, int &y){return x>y;});
        int cnt = 1;
        while(cnt < vec.size() && vec[cnt] == vec[0]) cnt++;
        return max(len, cnt + (n+1)*(vec[0]-1));
    }
};
// @lc code=end
//！！桶思想，讲的很好
//https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
//每个桶看作一轮任务，桶的数量由排序后任务量最多的那个任务来决定。
//桶的深度 由 等待时间 n 决定 , 深度为 n+1 
//(相当于哈：A--- A--- A--- A)  A---即为 n + 1  其中 1 为 A， n为等待时间
//等待呢必须要等待！但是 可以等待时候 顺便做其他任务~~提高效率！
//当 n > 任务种类时 
//总排队时间 = (桶个数 - 1) * (n + 1) + 最后一桶的任务数
//当 n < 任务种类时 完全空闲时间就可以做其他任务来填补了
