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
    int solve(TreeNode* root, int &cameras){
        if(root == NULL){
            return 1;
        }
        int leftStatus =  solve(root->left,cameras);
        int rightStatus = solve(root->right,cameras);
        if(leftStatus == 0 || rightStatus == 0){
            cameras++;
            return 2;
        }
        if(leftStatus == 2 || rightStatus == 2){
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        // robbing each node gives me one vlaue.. we have to return teh minium value...
        // now take the cases..
        int cameras = 0;
       if (solve(root,cameras) == 0){
            cameras++;
       }
        return cameras;
    }
};