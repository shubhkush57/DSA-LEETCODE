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
    bool solve(TreeNode* leftN,TreeNode* rightN){
        if((leftN == NULL && rightN != NULL) || (leftN != NULL && rightN == NULL)){
            return false;
        }
        else if(leftN == NULL && rightN == NULL){
            return true;
        }
        else if(leftN->val != rightN->val ){
            return false;
        }
        bool left =solve(leftN->left,rightN->right);
        bool  right = solve(leftN->right, rightN->left);
        return left && right;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return solve(root->left,root->right);
    }
};