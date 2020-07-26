//递归哇
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

//递归思想的迭代！（大佬的=。=）

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
                call.push(t);  //在左节点之前重新插入该节点，以便在左节点之后处理（访问值）
                call.push(nullptr); //nullptr跟随t插入，标识已经访问过，还没有被处理
                if(t->left) call.push(t->left);
            }else{
                res.push_back(call.top()->val);
                call.pop();
            }
        }
        return res;
    }
};

////常规迭代法（栈）
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
