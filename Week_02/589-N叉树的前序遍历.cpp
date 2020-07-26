////�ο��������ĵݹ������ʽ���ȱ������ڵ㣬Ȼ��ݹ�������������ٵݹ������������
//��N������ǰ����������ȱ������ڵ㣬Ȼ�����εݹ����ÿ��������
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        pre_order(res, root);
        return res;
    }
    void pre_order(vector<int>& res, Node* root){
        if(!root) return;
        res.push_back(root->val);
        for(int i = 0;i < root->children.size();i++){  //�ɸ���Ϊ     for (auto i : root->children)    pre_order(i, res);    
            Node *cur = root->children[i];
            if(cur){
                pre_order(res, cur);
            }
        }  
    }
};

//��������ÿ��ȡ������Ȼ������öຢ�Ӵ���������ջ��Ȼ���ټ���
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root)   return res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* tmp = stk.top();
            stk.pop();
            res.push_back(tmp -> val);
            for(int i = tmp -> children.size()-1; i >= 0; --i){
                stk.push(tmp -> children[i]);
            }
        }
        return res;
    }
};
