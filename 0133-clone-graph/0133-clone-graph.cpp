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
    void solve(Node* node,unordered_map<Node*,Node*>&nodeMapper,unordered_map<int,int>&vis){
        vis[node->val]= true;
        for(auto it: node->neighbors){
            if(!nodeMapper.count(it)){
                Node* newNode = new Node(it->val);
                nodeMapper[it] = newNode;
            }
            nodeMapper[node]->neighbors.push_back(nodeMapper[it]);
            if(!vis.count(it->val)){
                solve(it,nodeMapper,vis);
            }
        }
        
        return;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)return node;
        unordered_map<Node*,Node*>nodeMapper;
        unordered_map<int,int>vis;
        Node* newNode = new Node(node->val);
        nodeMapper[node] = newNode;
        solve(node,nodeMapper,vis);
        return nodeMapper[node];
    }
};