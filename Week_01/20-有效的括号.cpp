
//ע���ҵ�����ϵ��----��Ȼ�Ǽ���=��=������
//ʢˮ��������
class Solution {
public:
    bool isValid(string s) {
        if(s[0] == ')'||s[0]== ']'||s[0] == '}') return false;
        stack<char> stk;
        int slen = s.length();
        for(int i = 0;i < slen;i++){
            if(s[i] == '(')      stk.push(')');  //ͨ���˲���������Ϳ���ֱ�Ӷ�Ӧ��~~
            else if(s[i] == '{') stk.push('}');
            else if(s[i] == '[') stk.push(']'); 
            else if(!stk.empty()&&stk.top() == s[i]){
                stk.pop();
            }
            else 
                return false;                    
        }
        if(stk.empty()) return true;
        return false;
    }
};

//�Ż����������~~~���Щ��
/*
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0;i < s.length();i++){
            if(s[i] == '(')      stk.push(')');
            else if(s[i] == '{') stk.push('}');
            else if(s[i] == '[') stk.push(']'); 
            else if(!stk.empty()&&stk.top() == s[i]) stk.pop(); 
            else   return false;                    
        }
        return stk.empty();
    }
};
*/