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
        if(p->val > q->val){
            TreeNode* temp = q;
            q = p;
            p = temp;
        }
        if(root == p || root == q)return root;
        // now we can easy say that p will be alwasy less than q.
        if(root->val > p->val && root->val < q->val)return root;
        if(root->val > p->val && root->val>q->val)  return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);
    }
};