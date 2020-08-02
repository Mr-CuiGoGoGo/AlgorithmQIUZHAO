class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int result = 0;
        while (i != g.size() && j != s.size())
        {
            if (g[i] <= s[j])
            {
                result++;
                i++;
                j++;
            }
            else
                j++;
        }
        return result;
    }
};

//给一个孩子的饼干 应当尽量小并且又能满足该孩子，这样大饼干才能拿来给满足度比较大的孩子。
//满足度最小的孩子最容易得到满足，所以应先满足满足度最小的孩子
