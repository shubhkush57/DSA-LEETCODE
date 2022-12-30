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
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        queue<Node*>q;
        Node* temp = root;
        q.push(temp);
        while(!q.empty()){
            int t = q.size();
            for(int i = 0;i<t;i++){
                Node* f = q.front();
                q.pop();
                if(i ==  t-1){
                    f->next = NULL;
                }
                else{
                    f->next = q.front();
                }
                if(f->left != NULL){
                    q.push(f->left);
                }
                if(f->right != NULL){
                    q.push(f->right);
                }
            }
        }
        return root;
    }
};