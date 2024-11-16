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
    int distributeCoins(TreeNode* root) {
        // we have root a
        // reqirment is always about root->val+left+right-1;
        int ans = 0;
        solve(root,ans);
        return ans;
    }
    int solve(TreeNode* root,int &ans){
        if(root == NULL)return 0;
        int left = solve(root->left,ans);
        int right = solve(root->right,ans);
        ans += abs(left)+abs(right);
        return root->val+left+right-1;
    }
};