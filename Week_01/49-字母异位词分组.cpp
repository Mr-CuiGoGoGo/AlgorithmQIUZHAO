
//积累题目经验系列----自己写了好久=。=结果超时了，，还是要用哈希才可以。。（需要大量联系）
//字母异位词分组
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;  
        int sub=0;  //结果vector的下标值
        string tmp; 
        unordered_map<string,int> work; //判断排序后单词是否存在，即字母组成是否一致
        for(auto str:strs)
        {
            tmp=str;
            sort(tmp.begin(),tmp.end());
            if(work.count(tmp))
            {
               res[work[tmp]].push_back(str);
            }
            else
            {
                vector<string> vec(1,str);
                res.push_back(vec);
                work[tmp]=sub++;
            }
        }
        return res;
    }
};


//仍旧要去学习其他做法~~~。。先提交作业。。（已备案！）


