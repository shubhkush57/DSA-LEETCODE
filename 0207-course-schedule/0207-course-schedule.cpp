class Solution {
public:
    bool dfs(vector<vector<int>>&adjList,vector<int>&indegree,vector<bool>&vis,int node){
        for(auto it: adjList[node]){
            if(vis[it]) return false;
            indegree[it]--;
            if(indegree[it] == 0){
                vis[it] = true;
                if(!dfs(adjList,indegree,vis,it))return false;
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // indegree and dfs
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adjList(numCourses,vector<int>());
        for(auto it: prerequisites){
            adjList[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        vector<bool>vis(numCourses,false);
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0 && vis[i] == false){
                vis[i] = true;
                if(!dfs(adjList,indegree,vis,i))return false;
            }
        }
        for(auto it: vis){
            if(!it)return false;
        }
        return true;
    }
};