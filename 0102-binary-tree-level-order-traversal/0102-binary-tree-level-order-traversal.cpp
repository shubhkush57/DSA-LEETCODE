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
    void dfs(TreeNode* root,vector<vector<int>>& ans,int l){
        if(!root)return;
        if(l>=ans.size()){
            ans.push_back({});
        }
        ans[l].push_back(root->val);
        dfs(root->left,ans,l+1);
        dfs(root->right,ans,l+1);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        // can we do it using dfs..
        vector<vector<int>>ans;
        if(!root)return ans;
        dfs(root,ans,0);
        return ans;
    }
};