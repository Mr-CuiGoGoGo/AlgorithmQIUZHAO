
//参考超哥的思路。。但才击败了13%,仍需要优化。。。
class Solution {
public:
    set<int> cols, pie, na;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if(n < 1) return {};
        DFS(n, 0, {}, res);
        return res;
    }
    void DFS(int n, int row, vector<string> cur_state, vector<vector<string>>& res){
        if(row >= n){
            res.push_back(cur_state);
            return;
        }
        for(int col = 0; col < n;col++){
            if(cols.count(col)|| pie.count(row + col)|| na.count(row - col)){
                continue;
            }

            cols.insert(col);
            pie.insert(row + col);
            na.insert(row - col);
            string temp(n, '.');
            temp[col] = 'Q';
            cur_state.push_back(temp);//当前合适的Q这行打印的导入进去！
            
            DFS(n, row + 1, cur_state, res);//当前i行某列确定Q，探索i+1行后续各种情况
            
            cols.erase(col);
            pie.erase(row + col);
            na.erase(row - col);
            cur_state.pop_back();
        }
    }

};