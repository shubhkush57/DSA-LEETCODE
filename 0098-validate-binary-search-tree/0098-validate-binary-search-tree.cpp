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
    bool solve(TreeNode* root,long long MAX,long long MIN){
        if(!root)return true;
        if(root->val <=MIN || root->val >=MAX)return false;

        return solve(root->left,root->val,MIN) && solve(root->right,MAX,root->val);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return solve(root,LLONG_MAX,LLONG_MIN);
    }
};