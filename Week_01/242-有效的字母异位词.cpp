//咳咳，碰到可以暴力的都要先暴力一波试试 。。。。毕竟有的题目暴力思路都不会
//有效的字母异位词 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;  //这句是后来优化的。。
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// O(nlogn)

//哈希表（学习他人思路）~~ 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; 
        int wd[26] = {0};
        int i;
        for (i = 0; i < s.size(); i++){ 
            wd[s[i] - 'a']++;
            wd[t[i] - 'a']--;
		}
        for (i = 0; i < 26; i++) 
            if(wd[i])  return false;
        return true;
    }
};
