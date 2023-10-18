//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int n, vector<int> adj[], int x) 
	{
	    // code here
	    int ans = 0;
	    queue<int>q;
	    vector<bool>vis(n,false);
	    q.push(0);
	    vis[0] = true;
	    int level = 0;
	    while(!q.empty()){
	        int t = q.size();
	        while(t--){
	            int z  = q.front();q.pop();
	            if(z == x)return level;
	            for(auto it: adj[z]){
	                if(!vis[it]){
	                    q.push(it);
	                    vis[it] = true;
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends