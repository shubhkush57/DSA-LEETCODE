/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void solve(Node* node,Node* copyNode,unordered_map<Node*,Node*>& isCreated){
        for(auto it: node->neighbors){
            Node* nextNode;
            if(isCreated.count(it)){
                copyNode->neighbors.push_back(isCreated[it]);
            }
            else{   
                nextNode = new Node(it->val);
                isCreated[it] = nextNode;
                copyNode->neighbors.push_back(isCreated[it]);
                solve(it,nextNode,isCreated);
            }
            
            
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        // we have to make a deep copy
        if(node == NULL)return NULL;
        Node* copyNode = new Node(node->val);
        unordered_map<Node*,Node*>isCreated;
        isCreated[node] = copyNode;
        solve(node,copyNode,isCreated);
        return copyNode;
    }
};
// Problem 1.
// create the new node which are not yet been created

// Problem 2.
// store the node which you are creating in somewhere.. from which you can in 
// future look if you every have worked on thme.. means created

// problem 3.

// connect all the created node by there adjacent node.

// List<Node*> adjNodes... then create that..


// solution:

// use the DFS...