class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adjList(numCourses,vector<int>());
        for(auto it: prerequisites){
            adjList[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        vector<int>ans;
        vector<bool>vis(numCourses,false);
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0 && vis[i] == false){
                queue<int>q;q.push(i);ans.push_back(i);vis[i] = true;
                while(!q.empty()){
                    int t= q.size();
                    while(t--){
                        int f = q.front();q.pop();
                        for(auto it: adjList[f]){
                            indegree[it]--;
                            if(indegree[it] == 0){
                                q.push(it);
                                vis[it] = true;
                                ans.push_back(it);
                            }
                        }
                    }
                }
            }
        }

        if(ans.size() != numCourses)return {};
        return ans;
    }
};