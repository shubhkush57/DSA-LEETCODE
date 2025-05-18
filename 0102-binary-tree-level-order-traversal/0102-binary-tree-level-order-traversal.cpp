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
    void preorderTraversal(vector<vector<int>>&ans,TreeNode* root,int l){
        if(root == NULL){
            return;
        }
        if(l>= ans.size()){
            ans.push_back({});
        }
        ans[l].push_back(root->val);
        preorderTraversal(ans,root->left,l+1);
        preorderTraversal(ans,root->right,l+1);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        int l = 0;
        preorderTraversal(ans,root,l);
        return ans;
    }
};