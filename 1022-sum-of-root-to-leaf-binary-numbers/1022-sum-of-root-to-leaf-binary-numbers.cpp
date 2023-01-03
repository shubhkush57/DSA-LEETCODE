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
    void solve(TreeNode* root,int &sum,string &path){
        if(root->left == NULL && root->right == NULL){
            path.push_back(root->val + '0');
            cout<<path<<endl;
            int n = path.size();
            int p = 1;
            for(int i = n-1;i>=0;i--){
                sum += (path[i]-'0')*p;
                p = p*2;
            }
            return;
        }
        path.push_back(root->val+'0');
        if(root->left != NULL ){
            solve(root->left,sum,path);
            path.pop_back();
        }
        if(root->right != NULL){
            solve(root->right,sum,path);
            path.pop_back();
        }
        // path.pop_back();
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        string path = "";
        solve(root,sum,path);
        return sum;
    }
};