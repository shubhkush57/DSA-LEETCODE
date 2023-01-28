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
    void solve(TreeNode* root,bool goLeft,int maxPath,int &ans){
        ans = max(ans,maxPath);
        if(root == NULL){
            return;
        }
        if(goLeft){
            solve(root->left,false,maxPath+1,ans);
            solve(root->right,true,1,ans);
            // solve(root->left,true,0,ans);
            // solve(root->left,false,0,ans);
        }
        else{
            solve(root->right,true,maxPath+1,ans);
            solve(root->left,false,1,ans);
            // solve(root->right,false,0,ans);
            // solve(root->right,true,0,ans);
        }
        return ;
    }
    int longestZigZag(TreeNode* root) {
        bool goLeft = true;
        if(root== NULL){
            return 0;
        }
        int maxPath =0;
        int ans = 0;
        
        solve(root,goLeft,0,ans);
        solve(root,false,0,ans);
        return ans-1;
    }
};