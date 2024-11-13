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
    int solve(TreeNode* root,int &ans){
        if(root == NULL)return 0;
        int left = max(solve(root->left,ans),0);
        int right = max(solve(root->right,ans),0);
        ans = max(ans,root->val+left+right);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        // so this is our solution...
        // so moving on the coding part..
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};

// Algo...
// 1. base case.. if(root == NULL)return 0;

// 2. calcuate left = max(solve(root->left),0);
// 3. calculate right = max(solve(root->right),0);

// 4. ans= max(ans,root->val+left+right);

// return root->val+max(left,right);