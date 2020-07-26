//参考大佬代码。。。学习。
//枚举（此处要注意a=2a;b=3b;c=3c ）否则超时
//以及数据类型long
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        for (long long a=1;a<=INT_MAX;a=a*2)
            for (long long b=a;b<=INT_MAX;b=b*3)
                for (long long c=b;c<=INT_MAX;c=c*5)
                    v.push_back(c);
        sort(v.begin(),v.end());
        return v.at(n-1);
    }
};

//使用小顶堆~~（优先队列）
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <double,vector<double>,greater<double> > q;
        double answer=1;
        for (int i=1;i<n;++i)
        {
            q.push(answer*2);
            q.push(answer*3);
            q.push(answer*5);
            answer=q.top();
            q.pop();
            while (!q.empty() && answer==q.top())
                q.pop();
        }
        return answer;
    }
};

//参考大佬代码
//改进了下用static
class Solution {
public:
    int nthUglyNumber(int n) {
        static vector <int> results (1,1);
        static int i = 0, j = 0, k = 0;
        while (results.size() < n)
        {
            results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
            if (results.back() == results[i] * 2) ++i;
            if (results.back() == results[j] * 3) ++j;
            if (results.back() == results[k] * 5) ++k;
        }
        return results[n-1];
    }
};
