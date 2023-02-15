class Solution {
public:
    #define umapset unordered_map<int,set<int>>
    #define pp pair<int,int>
    vector<int> topoSort(umapset &mp,vector<vector<int>>&v,int k){
        int n = v.size();
        // find the indegree 
        set<vector<int>>st;
        for(auto it: v){
            st.insert(it);
        }
        vector<int>topo_sort;
        vector<int>indegree(k+1,0);
        vector<bool>vis(k+1,false);
        for(auto it: st){
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i = 1;i<=k;i++){
            if(indegree[i] == 0){
                q.push(i);
                vis[i] = true;
            }
        }
        while(!q.empty()){
            int f = q.front();q.pop();
            topo_sort.push_back(f);
            for(auto it: mp[f]){
                if(vis[it] == false){
                    indegree[it]--;
                    if(indegree[it] == 0){
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }
        }
        return topo_sort;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        umapset mp1;
        umapset mp2;
        for(auto it: rowConditions){
            mp1[it[0]].insert(it[1]);
        }
        for(auto it: colConditions){
            mp2[it[0]].insert(it[1]);
        }
        vector<int>row_topo = topoSort(mp1,rowConditions,k);
        vector<int>col_topo = topoSort(mp2,colConditions,k);
        if(row_topo.size() != k || col_topo.size() != k){
            return {};
        }
        // for(int i = 0;i<k;i++){
        //     cout<<row_topo[i]<<' '<<col_topo[i]<<endl;
        // }
        vector<vector<int>>ans(k,vector<int>(k,0));
        unordered_map<int,int>mp;
        for(int i = 0;i<k;i++){
            // ans[i][i] = col_topo[i];
            mp[col_topo[i]] = i;
        }
        for(int i = 0;i<k;i++){
            int position = mp[row_topo[i]];
            ans[i][position] = row_topo[i];
        }
        return ans;
            
    }
};