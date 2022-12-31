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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        if(root == NULL){
            return ans;
        }
        map<int,map<int,multiset<int>>>mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            int t = q.size();
            for(int i = 0;i<t;i++){
                // for each level
                TreeNode* fnode = q.front().first;
                int v = q.front().second.first;
                int l = q.front().second.second;
                q.pop();
                mp[v][l].insert(fnode->val);
                if(fnode->left != NULL){
                    q.push({fnode->left,{v-1,l+1}});
                }
                if(fnode->right != NULL){
                    q.push({fnode->right,{v+1,l+1}});
                }
            }
        }
        // now turn for the answer
        for(auto it1: mp){
            int v = it1.first;
            vector<int>vo;
            for(auto it2 : it1.second){
                int l = it2.first;
                // now push the whole
                for(auto valu : it2.second){
                    vo.push_back(valu);
                }
            }
            ans.push_back(vo);
        }
        return ans;
    }
};