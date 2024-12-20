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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,NULL}); // current root and it's parent
        int level = 0;
        while(!q.empty()){
            int t = q.size();
            vector<int> nodev;
            vector<TreeNode*>parv;
            for(int i = 0;i<t;i++){
                TreeNode* currot = q.front().first;
                TreeNode* par = q.front().second;
                q.pop();
                nodev.push_back(currot->val);
                parv.push_back(par);
                if(currot ->left != NULL){
                    q.push({currot->left,currot});
                }
                if(currot->right != NULL){
                    q.push({currot->right,currot});
                }
            }
            if(level%2 == 1){
                reverse(nodev.begin(),nodev.end());
                for(int i = 0;i<nodev.size();i++){
                    if(i%2 == 0){
                        parv[i]->left->val = nodev[i];
                    }
                    else if(i%2 == 1){
                        parv[i]->right->val = nodev[i];
                    }
                }
            }
            level++;
        }
            return root;

    }
};