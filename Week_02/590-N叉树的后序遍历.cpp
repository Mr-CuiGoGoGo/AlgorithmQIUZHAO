////参考N叉树的前序递归遍历方式~~~~递归，改下顺序即可
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        pre_order(res, root);
        return res;
    }
    void pre_order(vector<int>& res, Node* root){
        if(!root) return;
        for(int i = 0;i < root->children.size();i++){
            pre_order(res, root->children[i]);
        }    
        res.push_back(root->val);      
    }
};

//迭代法：参考前序遍历 根左右顺序 改为  遍历儿子 改为 根右左  然后反转一波就  左右根
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        if(root)  stk.push(root);
        while(!stk.empty()){
            Node* tmp = stk.top();
            res.push_back(tmp -> val);
            stk.pop();
            for(int i = 0;i < tmp->children.size(); ++i){
                if(tmp -> children[i]) stk.push(tmp -> children.at(i));
            }   
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
