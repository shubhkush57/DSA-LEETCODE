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
    struct Node{
        TreeNode* pointer;
        int value;
        Node() : value(0), pointer(nullptr){}
    };
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&mp){
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        // now you have permission to choose the node or not according to the 
//         if(choose == 0){
//             // you can choose that node or not
//             if(root->left != NULL){
//                int temp1  = root->val + solve(root->left,1);
//                 int temp2 = solve(root->left,0);
//                 ans += max(temp1,temp2);
//             }
//             if(root->right != NULL){
//                 int temp1 = root->val+solve(root->right,1);
//                 int temp2= solve(root->right,0);
//                 ans += max(temp1,temp2);
//             }
            
//         }
//         else{
//             // you have already choosen the previous ones
//             if(root->left != NULL){
//                 int temp  = solve(root->left,0);
//                 ans += temp;
//             }
//             if(root->right != NULL){
//                 int temp = solve(root->right,0);
//                 ans += temp;
//             }
//         }
        // suppose the previous no
        // Node* x = new Node();
        // x->pointer = root;
        // x->value = choose;
        // if(mp.count(x)){
        //     return mp[x];
        // }
        if(mp.count(root)){
            return mp[root];
        }
        int temp1 = root->val;
        if(root->left != NULL){
            temp1 += solve(root->left->left,mp);
            temp1 += solve(root->left->right,mp);
        }
        if(root->right != NULL){
            temp1 += solve(root->right->left,mp);
            temp1 += solve(root->right->right,mp);
        }
        ans = max(ans,temp1);
        int temp2 = 0;
        if(root->left != NULL){
            temp2 += solve(root->left,mp);
        }
        if(root->right != NULL){
            temp2 += solve(root->right,mp);
        }
        ans = max(ans,temp2);
        // if(choose == 0){
        //     int temp1 = root->val;
        //     if(root->left != NULL){
        //         temp1 += solve(root->left,1,mp);
        //     }
        //     if(root->right != NULL){
        //         temp1 += solve(root->right,1,mp);
        //     }
        //     ans = max(ans,temp1);
        //     int temp2  = 0;
        //     if(root->left != NULL){
        //         temp2 += solve(root->left,0,mp);
        //     }
        //     if(root->right != NULL){
        //         temp2 += solve(root->right,0,mp);
        //     }
        //     ans = max(ans,temp2);
        // }
        // else{
        //     // you cannot choose it's left or right
        //     int temp = 0;
        //     if(root->left != NULL){
        //          temp += solve(root->left,0,mp);
        //     }
        //     if(root->right != NULL){
        //         temp += solve(root->right,0,mp);
        //     }
        //     ans = temp;
        // }
        return mp[root] = ans;
    }
    int rob(TreeNode* root) {
        // DP+ tree question // DFS
        int ans = 0;
        int choose = 0;
        // unordered_map<Node*,int>mp;
        unordered_map<TreeNode*,int>mp;
        ans = solve(root,mp);
        return ans;
    }
};