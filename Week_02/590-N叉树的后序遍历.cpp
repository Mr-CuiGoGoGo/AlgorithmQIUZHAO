////�ο�N������ǰ��ݹ������ʽ~~~~�ݹ飬����˳�򼴿�
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

//���������ο�ǰ����� ������˳�� ��Ϊ  �������� ��Ϊ ������  Ȼ��תһ����  ���Ҹ�
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
