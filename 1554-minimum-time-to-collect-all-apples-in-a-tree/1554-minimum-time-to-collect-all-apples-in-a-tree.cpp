class Solution {
public:
    pair<int,int> solve(vector<vector<int>>&adj,vector<bool>&hasApple,vector<bool>&vis,int node){
        int n = hasApple.size();
        vis[node] = true;
        int ans = 0; 
        int apple = hasApple[node]?1:0;
        for(auto it: adj[node]){
            if(vis[it] == false){
                pair<int,int> part = solve(adj,hasApple,vis,it);
                if(part.second == 1){
                    ans += part.first + 2;
                }
                apple = apple | part.second;

            }
        }
        return {ans,apple};
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n,vector<int>());
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,false);
        pair<int,int> ans = solve(adj,hasApple,vis,0);
        return ans.first;
    }
};