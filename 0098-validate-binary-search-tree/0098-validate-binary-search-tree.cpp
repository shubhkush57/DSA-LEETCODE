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
//     bool isTrue(TreeNode* root,int minVal,int maxVal){
//         if(root == NULL){
//             return true;
//         }
//         if(root->val <= minVal || root->val >=maxVal){
//             return false;
//         }
//         return isTrue(root->left,minVal,root->val) && isTrue(root->right,root->val,maxVal);
        
//     }
    bool isTruee(TreeNode* root,long minval,long maxval){
        if(root == NULL){
            return true;
        }
        if(root->val <= minval || root->val >= maxval)return false;
        return isTruee(root->left,minval,root->val)&& isTruee(root->right,root->val,maxval);
    }
    bool isValidBST(TreeNode* root) {
        return isTruee(root,LONG_MIN,LONG_MAX);
    }
};