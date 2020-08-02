
//�ο������˼·�������Ż�����13%,����Ҫ�Ż�������
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
            cur_state.push_back(temp);//��ǰ���ʵ�Q���д�ӡ�ĵ����ȥ��
            
            DFS(n, row + 1, cur_state, res);//��ǰi��ĳ��ȷ��Q��̽��i+1�к����������
            
            cols.erase(col);
            pie.erase(row + col);
            na.erase(row - col);
            cur_state.pop_back();
        }
    }

};