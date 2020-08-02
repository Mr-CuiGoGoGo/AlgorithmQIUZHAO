class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>  map={
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"},
            {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},
            {'8',"tuv"}, {'9',"wxyz"}
        };
        if(digits.empty()) return {};//����û�оͻᱨ����   ����  -----> [""] ( �� )    ""( �� )
        vector<string> res;
        lc(res, 0, "", digits, map);
        return res;
    }
    void lc(vector<string> &res, int i, string str, string digits, unordered_map<char, string> map){
        //terminator
        if(i == digits.size()){
            res.push_back(str);
            return;
        }
        //process
        string temp = map[digits[i]]; 
        //cout <<temp <<endl;
        for(int j = 0;j < temp.size();j++){
            lc(res, i + 1, str + temp[j], digits, map);
        }
        return;
    }
};
//˳�ų��署�� ������ϵ�˼·������������Ŀ��������