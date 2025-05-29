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

class BSTNode{
public:
    long sum ;
    long min_;
    long max_;
    BSTNode(long sum,long leftMin,long righMax){
        this->sum = sum;
        this->min_=leftMin;
        this->max_ = righMax;
    }
};

class Solution {
public:
    BSTNode* solve(TreeNode* root, long &ans){
        if(root == NULL){
            return new BSTNode(0L,LLONG_MAX,LLONG_MIN);
        }
        BSTNode* left = solve(root->left,ans);
        BSTNode* right = solve(root->right,ans);
        long sum_ = root->val+left->sum+right->sum;
        if(root->val> left->max_ && root->val<right->min_){
            ans = max(ans,sum_);
            return new BSTNode(sum_,min((long)root->val,left->min_),max((long)root->val,right->max_));
        }
        return new BSTNode(sum_,INT_MIN,INT_MAX);
    }
    int maxSumBST(TreeNode* root) {
        long ans = 0;
        solve(root,ans);
        return ans;
    }
};