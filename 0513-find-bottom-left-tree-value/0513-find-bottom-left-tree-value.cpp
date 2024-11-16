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
    void solve(TreeNode* root,int &d,int &ans,int level){
        if(root == NULL)return ;
        if(d<=level){
            ans = root->val;
            d++;
        }
        solve(root->left,d,ans,level+1);
        solve(root->right,d,ans,level+1);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        // last row i   
        int d = 0;
        int ans = 0;
        solve(root,d,ans,0);

        return ans;
    }
};