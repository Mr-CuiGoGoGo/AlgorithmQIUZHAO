class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0){
            x = 1 / x;
            N = -N;
        }
        return pow(x, N);
    }
    double pow(double x, long long n){
        //terminator
        if(n == 0) return 1.0;
        //process
        double half = pow(x, n/2);
        //merge
        if(n % 2 == 0){
            return half * half;
        } else {
            return half * half * x;
        }
    }
};

//����  �мǵ�n=-2^31ʱ NΪ2^31������int���ֵ��2^31-1��,����Ҫ��long long��������