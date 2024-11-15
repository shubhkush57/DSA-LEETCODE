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
    string serialize(TreeNode* root){
        if(root == NULL){
            return "()";
        }
        string ans = "("+to_string(root->val)+"#";
        string LeftPart = serialize(root->left);
        ans += LeftPart;
        ans += "#";
        string RightPart = serialize(root->right);
        ans += RightPart;
        return ans ;
        
    }
    string solve(TreeNode* root, vector<TreeNode*>&desiredAns,unordered_map<string,int>&memory){
        if(root == NULL){
            return "()";
        }
        string ans = "("+to_string(root->val)+"#";
        string LeftPart = solve(root->left,desiredAns,memory);
        ans += LeftPart;
        ans += "#";
        string RightPart = solve(root->right,desiredAns,memory);
        ans += RightPart;
        if(memory.count(ans) && memory[ans] == 1){
            desiredAns.push_back(root);
        }
        memory[ans]++;
        return ans ;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // can we serialize subtree
        vector<TreeNode*> ans;
        unordered_map<string,int>memory;
        solve(root,ans,memory);
        for(auto it: memory){
            cout<<it.first<<endl;
        }
        return ans;
        
    }
};

// (rootValeu#LeftPart#RightPart);