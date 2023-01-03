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
    TreeNode* solve(vector<int>&in,vector<int>&po,int ins,int ine,int pos,int poe,map<int,int>&mp){
        if(ins> ine || pos> poe){
            return NULL;
        }
        TreeNode* root = new TreeNode(po[pos]);
        int ind = mp[po[pos]];
        int siz = ine-ind;
        root->left = solve(in,po,ins,ind-1,pos+siz+1,poe,mp);
        root->right = solve(in,po,ind+1,ine,pos+1,pos+siz,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        int n= in.size();
        map<int,int>mp;
        for(int i = 0;i<n;i++){
            mp[in[i]] = i;
        }
        reverse(po.begin(),po.end());
        int ins = 0;int ine = n-1;int pos = 0;int poe = n-1;
        return solve(in,po,ins,ine,pos,poe,mp);
    }
};