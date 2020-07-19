
//注：找到自信系列----虽然是简单题=。=。。。
//盛水最多的容器
class Solution {
public:
    bool isValid(string s) {
        if(s[0] == ')'||s[0]== ']'||s[0] == '}') return false;
        stack<char> stk;
        int slen = s.length();
        for(int i = 0;i < slen;i++){
            if(s[i] == '(')      stk.push(')');  //通过此操作，后面就可以直接对应了~~
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

//优化后可以这样~~~简洁些吧
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