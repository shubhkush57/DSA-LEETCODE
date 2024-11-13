class Solution {
public:
    bool dfs(vector<int>&indegree,vector<bool>&vis,vector<vector<int>>&adj,int node){
        for(auto it: adj[node]){
            if(vis[it])return false;
            indegree[it]--;
            if(indegree[it] == 0){
                vis[it] = true;

                if(!dfs(indegree,vis,adj,it))return false;
            }
            
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses,vector<int>());
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        vector<bool>vis(numCourses,false);
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0 && vis[i] == false){
                vis[i] = true;
                if(!dfs(indegree,vis,adj,i))return false;
            }
        }
        
        for(auto it: vis){
            if(it == false)return false;
        }
        return true;

    }
};