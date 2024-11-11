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
    bool comp(TreeNode * root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL)return true;
        if(root == NULL || subRoot == NULL || root->val != subRoot->val)return false;
        return comp(root->left,subRoot->left) && comp(root->right,subRoot->right);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // for each root we will be comparing the anwer...
        bool ans = comp(root,subRoot);
        if(root->left != NULL)
        ans = ans or isSubtree(root->left,subRoot);
        if(root->right != NULL)
        ans = ans or isSubtree(root->right,subRoot);
        return ans;
    }
};