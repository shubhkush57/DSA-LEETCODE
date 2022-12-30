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
    void inorder(TreeNode* root,unordered_map<int,int>&v){
        if(root == NULL){
            return;
        }
        inorder(root->left,v);
        v[root->val]++;
        inorder(root->right,v);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>v;
        inorder(root,v);
        // now find the vlaues in teh
        for(auto it: v){
            
            if(it.first *2 != k && v.count(k-it.first)){
                return true;
            }
        }
        return false;
    }
};