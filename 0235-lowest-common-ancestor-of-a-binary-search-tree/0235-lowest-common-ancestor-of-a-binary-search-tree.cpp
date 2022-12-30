/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return root;
        }
        TreeNode* curr = root; // if one node is oon left and another is right then root is LCA
        if(curr->val > p->val && curr->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(curr->val < p->val && curr->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};