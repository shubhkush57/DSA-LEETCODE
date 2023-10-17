//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool topoSort(vector<int> adj[],int n,vector<int>&vis,vector<int>&inStack,int node){
        if(inStack[node]){
            return true;
        }
        if(vis[node]){
            return false;
        }
        inStack[node] = true;
        vis[node] = true;
        for(auto it: adj[node]){
            if(topoSort(adj,n,vis,inStack,it)){
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        // we need to know the nodes which are not making the circles....
        vector<int>vis(n,false);
        vector<int>inStack(n,false);
        for(int i = 0;i<n;i++){
            topoSort(adj,n,vis,inStack,i);
        }
        vector<int>ans;
        for(int i = 0;i<n;i++){
            if(!inStack[i]){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends