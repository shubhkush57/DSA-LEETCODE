/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
     TreeNode* solve(int l,int r, vector<int>&v){
        if(l == r){
            return NULL;
        }
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = solve(l,mid,v);
        root->right = solve(mid+1,r,v);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>v;
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
        
        return solve(0,v.size(),v);
    }
};