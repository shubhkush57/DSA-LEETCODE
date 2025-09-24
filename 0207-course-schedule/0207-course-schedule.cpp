class Solution {
public:
    bool isCompleted(vector<vector<int>>&adjList,vector<int>&indegree,vector<bool>&vis,int node){
        if(vis[node] == true)return false;
        vis[node] = true;
        for(auto it: adjList[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                if(!isCompleted(adjList,indegree,vis,it))return false;
            }
        }

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjList(numCourses,vector<int>());
        vector<int>indegree(numCourses,0);
        vector<bool>vis(numCourses,false);
        for(auto it: prerequisites){
            adjList[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i =0;i<numCourses;i++){
            if(vis[i] == false && indegree[i] == 0){
                if(!isCompleted(adjList,indegree,vis,i))return false;
            }
        }
        for(int i =0 ;i<numCourses;i++){
            if(vis[i] == false)return false;
        }
        return true;
    }
};