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
#define int2 long long
    #define pp pair<TreeNode*,int2>
    int widthOfBinaryTree(TreeNode* root) {
        queue<pp>q;
        int2 ans  = 0;
        int2 prev = 0;
        q.push({root,0});
        while(!q.empty()){
            int t = q.size();
            prev = q.front().second;
            for(int i= 0;i<t;i++){
                TreeNode* node = q.front().first;
                int2 val = q.front().second;
                q.pop();
                 if(i == t-1){
                    ans = max(ans,val-prev+1);
                }
                if(node->left != NULL){
                    q.push({node->left,2*val+1L-prev});
                }
                if(node->right != NULL){
                    q.push({node->right,2*val+2-prev});
                }
            }
        }

        return ans;
    }
};