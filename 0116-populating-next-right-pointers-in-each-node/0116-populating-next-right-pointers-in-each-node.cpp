/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve(Node* root,vector<vector<Node*>>&levelOrder, int level){
        if(root ==NULL)return;
        if(level>=levelOrder.size()){
            levelOrder.push_back({});
        }
        if(levelOrder[level].size()>0)levelOrder[level].back()->next = root;
        levelOrder[level].push_back(root);
        solve(root->left,levelOrder,level+1);
        solve(root->right,levelOrder,level+1);
        return;
    }
    Node* connect(Node* root) {
        // using dfs , applying concept of level order traversing..........
        vector<vector<Node*>>levelOrder;
        int level = 0;
        solve(root,levelOrder,level);
        return root;
        
    }
};