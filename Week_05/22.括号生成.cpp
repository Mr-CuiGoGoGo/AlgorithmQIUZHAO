class Solution {
public:
   vector<string> result;
vector<string> generateParenthesis(int n) {
    helper("", n, 0);
    return result;
}

/*  this hepler function insert result strings to "vector<string> result"
	When number of '(' less than "n", can append '(';
	When number of '(' is more than number of ')', can append ')';

	string s : current string;
	int leftpare_need : number of '(' that have not put into "string s";
	int moreleft : number of '(' minus number of ')' in the "string s";
*/

void helper(string s, int leftpare_need, int moreleft)
{
	if(leftpare_need == 0 && moreleft == 0)
	{
	    result.push_back(s);
	    return;
	}
	if(leftpare_need > 0)
		helper(s + "(", leftpare_need - 1, moreleft+1);
	if(moreleft > 0)
		helper(s + ")", leftpare_need, moreleft - 1);
}
};

//类似回溯，就是要提前去除不合理的情况来进行运算。节省了大量时间
//如果等生成了括号在判断是否合法，就会大大增加工作量