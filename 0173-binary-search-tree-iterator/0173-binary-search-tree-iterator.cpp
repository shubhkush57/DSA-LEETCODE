/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int>inorder;
    int i;
    BSTIterator(TreeNode* root) {
        solve(root,inorder);
        i = -1;;
    }
    void solve(TreeNode* root,vector<int>&inorder){
        if(root == NULL){
            return;
        }
        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
        return;
    }
    int next() {
        i++;
        return inorder[i];
    }
    
    bool hasNext() {
        if(i+1 >= inorder.size()){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */