////参考二叉树的递归遍历方式：先遍历根节点，然后递归遍历左子树，再递归遍历右子树。
//二N叉树的前序遍历就是先遍历根节点，然后依次递归遍历每个子树。
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
        for(int i = 0;i < root->children.size();i++){  //可改善为     for (auto i : root->children)    pre_order(i, res);    
            Node *cur = root->children[i];
            if(cur){
                pre_order(res, cur);
            }
        }  
    }
};

//迭代法：每次取出根，然后下面好多孩子从右往左入栈，然后再计算
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
