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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        if(root == NULL){
            return ans;
        }
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int t = q.size();
            long long f = q.front().second;
            long long e = q.back().second;
            ans = max(ans,e-f+1);
            // on the each level we are going to get his
            for(int i =0;i<t;i++){
                TreeNode* frnt = q.front().first;
                long long no = q.front().second;
                q.pop();
                no =  no-f;
                if(frnt->left != NULL){
                    q.push({frnt->left,(long long)2*no +(long long)1});
                }
                if(frnt->right != NULL){
                    q.push({frnt->right,(long long)2*no+(long long)2});
                }
            }
        }
        return ans;
    }
};