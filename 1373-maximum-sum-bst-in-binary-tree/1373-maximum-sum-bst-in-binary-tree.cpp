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
class ReqNode{
    public:
    int maxVal;
    int minVal;
    long sum = 0;
    ReqNode(int maxVal,int minVal,long sum){
        this->maxVal = maxVal;
        this->minVal = minVal;
        this->sum = sum;
    }
};
class Solution {
public:
    ReqNode solve(TreeNode* root,long &ans){
        if(root == NULL){
            return ReqNode(INT_MIN,INT_MAX,0);
        }
        // post order
        ReqNode left = solve(root->left,ans);
        ReqNode right = solve(root->right,ans);
        if(root->val > left.maxVal && root->val < right.minVal){
            // we have  found the one BST
            // so our answer 
            ans = max(ans,(long)root->val+left.sum + right.sum);
            return ReqNode(max(root->val,right.maxVal),min(root->val,left.minVal),root->val+left.sum+right.sum);
        }
        return ReqNode(INT_MAX,INT_MIN,root->val+left.sum+right.sum);
    }
    int maxSumBST(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        long ans = 0;
        solve(root, ans);
        return ans;
    }
};