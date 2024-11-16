class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>outdegree(n,0);
        vector<vector<int>>who_land(n,vector<int>());
        for(int i = 0;i<n;i++){
            outdegree[i] = graph[i].size();
            for(auto it: graph[i]){
                who_land[it].push_back(i);
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i = 0;i<n;i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int t =q.size();
            while(t--){
                int node = q.front();q.pop();
                ans.push_back(node);
                for(auto it: who_land[node]){
                    outdegree[it]--;
                    if(outdegree[it] ==0){
                        q.push(it);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};