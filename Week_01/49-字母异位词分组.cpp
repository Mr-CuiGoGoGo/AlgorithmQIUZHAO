
//������Ŀ����ϵ��----�Լ�д�˺þ�=��=�����ʱ�ˣ�������Ҫ�ù�ϣ�ſ��ԡ�������Ҫ������ϵ��
//��ĸ��λ�ʷ���
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;  
        int sub=0;  //���vector���±�ֵ
        string tmp; 
        unordered_map<string,int> work; //�ж�����󵥴��Ƿ���ڣ�����ĸ����Ƿ�һ��
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


//�Ծ�Ҫȥѧϰ��������~~~�������ύ��ҵ�������ѱ�������


