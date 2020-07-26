//�ݹ���
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;
        if(root->left != nullptr)  inorderTraversal(root->left);
        res.push_back(root->val);
        if(root->right != nullptr)  inorderTraversal(root->right);
        return res;
    }
};

//�ݹ�˼��ĵ����������е�=��=��

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> call;
        if(root!=nullptr) call.push(root);
        while(!call.empty()){
            TreeNode *t = call.top();
            call.pop();
            if(t!=nullptr){
                if(t->right) call.push(t->right);
                call.push(t);  //����ڵ�֮ǰ���²���ýڵ㣬�Ա�����ڵ�֮��������ֵ��
                call.push(nullptr); //nullptr����t���룬��ʶ�Ѿ����ʹ�����û�б�����
                if(t->left) call.push(t->left);
            }else{
                res.push_back(call.top()->val);
                call.pop();
            }
        }
        return res;
    }
};

////�����������ջ��
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || st.size()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();  st.pop();
            res.push_back(cur->val);
            cur = cur-> right;
        }
        return res;
    }
};
