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
    TreeNode* solve(vector<int>&preorder,vector<int>&postorder,int pres,int pree,int pos,int poe,map<int,int>&mp){
        if(pres > pree || pos > poe){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pres]);
        if(pres == pree){
            return root;
        }
        //since you have to check for the next element so do check the edge condtition
        int ind = mp[preorder[pres+1]];
        int siz = ind-pos+1;
        root->left = solve(preorder,postorder,pres+1,pres+siz,pos,ind,mp);
        root->right = solve(preorder,postorder,pres+siz+1,pree,ind+1,poe-1,mp);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int>mp;
        int n = preorder.size();
        for(int i = 0;i<n;i++){
            mp[postorder[i]] = i;
        }
        int pres = 0;
        int pree = n-1;
        int pos = 0;
        int poe = n-1;
        return solve(preorder,postorder,pres,pree,pos,poe,mp);
    }
};