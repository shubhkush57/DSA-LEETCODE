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
    TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int preorders,int preordere,int inorders,int inordere,map<int,int>&mp){
        if(preorders > preordere || inorders > inordere){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preorders]);
        int ind = mp[preorder[preorders]];
        int siz = ind-inorders;
        root->left = solve(preorder,inorder,preorders+1,preorders+siz,inorders,ind-1,mp);
        root->right = solve(preorder,inorder,preorders+siz+1,preordere,ind+1,inordere,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int n = preorder.size();
        for(int i = 0;i<n;i++){
            mp[inorder[i]] = i;
        }
        int preorders = 0;
        int preordere = n-1;
        int inorders = 0;
        int inordere = n-1;
        return solve(preorder,inorder,preorders,preordere,inorders,inordere,mp);
    }
};