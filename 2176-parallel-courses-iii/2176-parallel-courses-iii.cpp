class Solution {
public:
    #define pp pair<int,int>
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>indegree(n+1,0);
        queue<int>q;
        vector<bool>vis(n+1,false);
        vector<vector<int>>adj(n+1,vector<int>());
        for(int i = 0;i<relations.size();i++){
            adj[relations[i][0]].push_back(relations[i][1]);
            indegree[relations[i][1]]++;
        }
        vector<int>month(n+1,0);
        for(int i =1;i<=n;i++){
            if(indegree[i] == 0){
                q.push(i);
                month[i] = time[i-1];
                vis[i] = true;
            }
        }

        while(!q.empty()){
            int t = q.size();
            for(int i = 0;i<t;i++){
                int f = q.front();q.pop();
                for(auto it: adj[f]){
                    if(vis[it] == false){
                        indegree[it]--;
                        month[it] = max(month[it],month[f]+time[it-1]);
                        if(indegree[it] == 0){
                            q.push(it);
                            vis[it] = true;

                        }
                    }
                    
                }
            }
        }
        return *max_element(month.begin(),month.end());
    }
};