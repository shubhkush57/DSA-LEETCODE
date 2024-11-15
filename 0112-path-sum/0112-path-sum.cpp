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
    void solve(TreeNode* root, int targetSum,int& sum,bool &ans){
        if(root == NULL)return;
        sum += root->val;
        if(root->left == NULL && root->right == NULL && sum == targetSum){
            ans = true;
            return;
        }
        solve(root->left,targetSum,sum,ans);
        solve(root->right,targetSum,sum,ans);
        sum -= root->val;
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // can we write backtrack solution
        bool ans = false;
        int sum = 0;
        solve(root,targetSum,sum,ans);
        return ans;
    }
};