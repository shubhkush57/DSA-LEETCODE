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
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL){
            return ;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* cur = stk.top();
            stk.pop();
            if(cur->right != NULL){
                stk.push(cur->right);
            }
            if(cur->left != NULL){
                stk.push(cur->left);
            }
            if(!stk.empty()){
                cur->right = stk.top();
            }
            cur->left = NULL;
        }
        return;
    }
};