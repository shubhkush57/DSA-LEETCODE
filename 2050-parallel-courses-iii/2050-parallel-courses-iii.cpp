class Solution {
public:
    #define pp pair<int,int>
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // 
        vector<int>indegree(n+1,0);
        queue<int>q;
        vector<bool>vis(n+1,false);
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i<relations.size();i++){
            mp[relations[i][0]].push_back(relations[i][1]);
        }
        // for(auto it: mp){
        //     cout<<it.first<<' ';
        //     for(auto it2: it.second){
        //         cout<<it2<<' ';
        //     }
        //     cout<<endl;
        // }
        for(int i =0;i<relations.size();i++){
            indegree[relations[i][1]]++;
        }
        vector<int>month(n+1,0);
        for(int i =1;i<=n;i++){
            if(indegree[i] == 0){
                q.push(i);
                // cout<<i<<endl;
                month[i] = time[i-1];
                vis[i] = true;
            }
        }
        
        // for(auto it: indegree){
        //     cout<<it<<endl;
        // }
         // time for completion of each task
        int ans = 0;
        while(!q.empty()){
            int t = q.size();
            int mini = 0;
            for(int i = 0;i<t;i++){
                int f = q.front();q.pop();
                // mini = max(mini,time[f-1]);
                // month[f] = 
                for(auto it: mp[f]){
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
            // cout<<mini<<endl;
            ans += mini;
        }
        return *max_element(month.begin(),month.end());
    }
};