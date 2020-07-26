//递归哇
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;
        if(root->left != nullptr)  inorderTraversal(root->left);
        if(root->right != nullptr)  inorderTraversal(root->right);
		res.push_back(root->val);
        return res;
    }
};

//递归思想的迭代！（大佬的=。=）
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            if(cur != nullptr){
                st.push(cur);
                st.push(nullptr);
                if(cur->right) st.push(cur->right);
                if(cur->left)  st.push(cur->left); 
            } else{
                res.push_back(st.top()->val);
                st.pop();
            }
        } 
        return res;
    }
};

////常规迭代法（栈）
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            if(cur != nullptr){
                st.push(cur);
                st.push(nullptr);
                if(cur->right) st.push(cur->right);
                if(cur->left)  st.push(cur->left); 
            } else{
                res.push_back(st.top()->val);
                st.pop();
            }
        } 
        return res;
    }
};
