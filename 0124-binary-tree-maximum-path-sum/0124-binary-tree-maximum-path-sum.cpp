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
    int solve(TreeNode* root, int &ans){
        if(root == NULL){
            return 0;
        }
        int left = max(0,solve(root->left,ans));
        int right = max(0,solve(root->right,ans));
        ans = max(ans,root->val+left+right);
        return root->val+ max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        // need to return the maximum path sum
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};