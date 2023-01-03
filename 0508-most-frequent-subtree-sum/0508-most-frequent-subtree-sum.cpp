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
    int solve(TreeNode* root,map<int,int>&mp){
        if(root == NULL){
            return 0;
        }
        int left = solve(root->left,mp);
        int right = solve(root->right,mp);
        int temp = root->val+left+right;
        mp[temp]++;
        return temp;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // sub tree sum
        vector<int>ans;
        map<int,int>mp;
        // subtree sum 
        solve(root,mp);
        // take the most frequent terms
        vector<vector<int>>v;
        for(auto it: mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int count = v[0][0];
        for(auto it: v){
            // cout<<it[0]<<' '<<it[1]<<endl;
            if(it[0] == count){
                ans.push_back(it[1]);
            }
        }
        return ans;
        
    }
};