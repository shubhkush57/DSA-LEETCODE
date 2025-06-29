class Solution {
public:
    bool dfs(vector<vector<int>>&adjList,vector<int>&indegree,vector<int>&visited,int node){
        for(auto it: adjList[node]){
            if(visited[it] == 1)return false;
            indegree[it]--;
            if(indegree[it] ==0){
                visited[it] = 1;
                if(!dfs(adjList,indegree,visited,it))return false;
            }
        }

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adjList(numCourses,vector<int>());
        vector<int>indegree(numCourses,0),visited(numCourses,0);
        for(auto it: prerequisites){
            adjList[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0 && visited[i] == 0){
                visited[i] = 1;
                if(!dfs(adjList,indegree,visited,i))return false;
            }
        
        }
        for(int i = 0;i<numCourses;i++){
            if(visited[i] == 0)return false;
        }
        return true;

    }
};