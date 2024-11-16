class Solution {
public:
    #define pp pair<int,int>  
    //i -> (j , cost)
    int dfs(vector<vector<pp>>&adj,vector<bool>&vis,int node){
        vis[node] = true;
        int ans =0;
        for(auto it: adj[node]){
            if(vis[it.first] == false){
                ans += it.second+dfs(adj,vis,it.first);
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pp>>adj(n);
        for(auto it: connections){
            adj[it[0]].push_back({it[1],0});
            adj[it[1]].push_back({it[0],1});
        }
        vector<bool>vis(n,false);
        return n-dfs(adj,vis,0)-1;
    }
};
// make the alteration...