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
    TreeNode* invertTree(TreeNode* root) {
        // we have to invert the binary tree.
        if(root == NULL)return root;

        TreeNode* right  = root->right;
        root->right = root->left;
        root->left = right;
        invertTree(root->left)  ;
        invertTree(root->right);
        return root;

    }
};