//参考大佬代码。。。学习。
//采用队列~~
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> qe;
        if(root) qe.push(root);
        while(qe.size()){
            int size = qe.size();
            vector<int> cur;
            for(int i = 0;i < size;i++){
                Node* temp = qe.front();
                cur.push_back(temp->val);
                qe.pop();
                for(auto j : temp->children){
                    qe.push(j);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
    
};