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
    void solve(TreeNode* root,unordered_map<int,int>&mp,int &ans){
        if(root== NULL)return;
        mp[root->val]++;
        if(root->left == NULL && root->right == NULL){
            int odd = 0;
            for(auto it: mp){
                odd += (it.second)%2;
            }
            if(odd <=1)ans++;
        }
        solve(root->left,mp,ans);
        solve(root->right,mp,ans);
        mp[root->val]--;
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mp;
        int ans = 0;
        solve(root,mp,ans);
        return ans;
    }
};