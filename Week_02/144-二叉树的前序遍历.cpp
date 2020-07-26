//递归哇（这种舒服些。。写个子函数）
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(res, root);
        return res;
    }
private:
    void preorder(vector<int>& res, TreeNode* root){
        if(!root) return;
        res.push_back(root->val);
        preorder(res, root->left);
        preorder(res, root->right); 
    }

};

//常规迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || st.size()){
            while(cur){
                st.push(cur->right);
                res.push_back(cur->val);
                cur = cur->left;
            }
            cur = st.top(); 
            st.pop();
        }
        return res;
    }


};