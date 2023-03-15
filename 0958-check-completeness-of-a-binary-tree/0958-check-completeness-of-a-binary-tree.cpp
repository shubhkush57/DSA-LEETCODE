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
    // BFS approach
    #define pp pair<TreeNode*,int>
    bool isCompleteTree(TreeNode* root) {
        bool last = false;
        if(root == NULL){
            return true;
        }
        int level = 0;
        queue<pp>q;            
        int prev = 0;

        q.push({root,0});
        while(!q.empty()){
            int siz = q.size();
            if(siz != pow(2,level) && last == false){
                if(last == false){
                    last = true;
                }
                else{
                    cout<<"HERE"<<endl;
                    return false;
                }
            }
            for(int j = 0;j<siz;j++){
                pp f = q.front();
                q.pop();
               
                if(f.second != prev){
                    cout<<"here1"<<endl;
                    return false;
                }
                prev++;
                // now we will insert 
                if(f.first->left != NULL){
                    q.push({f.first->left,2*f.second+1});
                }
                if(f.first->right != NULL){
                    q.push({f.first->right,2*f.second+2});
                }
            }
            
            
            level++;
        }
        return true;
        
    }
};