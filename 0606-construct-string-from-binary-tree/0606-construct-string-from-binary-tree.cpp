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
    string solve(TreeNode* root){
        if(root == NULL)return "";
        string ans = "(";
        ans += to_string(root->val);
        if(root->left == NULL && root->right != NULL){
            ans += "()";
        }
        else{
            ans += solve(root->left);
        }
        // if(root->right == NULL && root->left != NULL){
        //     ans += "()";
        // }
        // else{
        //     ans += solve(root->right);
        // }
        ans += solve(root->right);
        ans += ")";
        return ans;
        
    }
    string tree2str(TreeNode* root) {
        if(root == NULL)return "";
        string ans = solve(root);
        int n = ans.size();
        return ans.substr(1,n-2);
    }
};