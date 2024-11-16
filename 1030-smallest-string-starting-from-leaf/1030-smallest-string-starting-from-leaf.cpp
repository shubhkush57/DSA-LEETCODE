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
    static bool comp(string &s1,string &s2){
        return s1>s2;
    }
    void solve(TreeNode* root,string &ans,string &re){
        if(root == NULL){
            return;
        }
        re.push_back('a'+root->val);
        if(root->left == NULL && root->right == NULL){
            reverse(re.begin(),re.end());
            if(ans == "" || comp(ans,re)){
                ans = re;
            }
            reverse(re.begin(),re.end());
        }
        solve(root->left,ans,re);
        solve(root->right,ans,re);
        re.pop_back();
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string re = "";
        solve(root,ans,re);
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};