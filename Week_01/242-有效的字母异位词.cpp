//�ȿȣ��������Ա����Ķ�Ҫ�ȱ���һ������ ���������Ͼ��е���Ŀ����˼·������
//��Ч����ĸ��λ�� 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;  //����Ǻ����Ż��ġ���
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// O(nlogn)

//��ϣ��ѧϰ����˼·��~~ 
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
