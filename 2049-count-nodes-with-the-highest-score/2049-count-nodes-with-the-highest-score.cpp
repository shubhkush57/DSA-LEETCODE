class Solution {
public:
    void solve(map<int,vector<int>>&mp,vector<int>&nodeattach,int i){
        if(mp.count(i) == false){
            nodeattach[i] = 1;
            return;
        }
        for(auto it: mp[i]){
            solve(mp,nodeattach,it);
            nodeattach[i] += nodeattach[it];
        }
        return;
        
    }
    int countHighestScoreNodes(vector<int>& parents) {
        vector<int>temp = {-1,0};
        if(parents == temp){
            return 2;
        }
        // how many nodes one nodes has
        map<int,vector<int>>mp;
        int n = parents.size();
        long long ans = 1;
        for(int i = 0;i<n;i++){
            mp[parents[i]].push_back(i);
            // -1 -> 0
            // 2 -> 1, 3
            // 0-> 2,4
        }
        vector<int>nodeattach(n,1);
        int i = 0;
        solve(mp,nodeattach,i);
        // for(auto it: mp){
        //     cout<<it.first<<"->";
        //     for(auto it2: it.second){
        //         cout<<it2<<' ';
        //     }
        //     cout<<endl;
        // }
        // cout<<"----------"<<endl;
        // for(int i = 0;i<n;i++){
        //     cout<<i<<"->" <<nodeattach[i]<<endl;
        // }
        // now time to dissconnect the terms
        unordered_map<long long,long long>counter;
        for(int i = 0;i<n;i++){
            // if we disconnect each node and  store the values
            if(i == 0){
                long long pro = 1;
                for(auto it: mp[0]){
                    pro = pro*(long long)nodeattach[it];
                }
                counter[pro]++;
                
            }
            else if(mp.count(i) == false){
                counter[nodeattach[0]-1]++;
                
            }
            else{
                long long pro = 1;
                for(auto it: mp[i]){
                    pro = pro*(long long)nodeattach[it];
                }
                pro = pro *(long long)( nodeattach[0]-nodeattach[i]);
                counter[pro]++;
                
            }
        }
        // cout<<"---"<<endl;
        long long pro = 1;
        for(auto it : counter){
            if(pro < it.first){
                pro = it.first;
                ans = it.second;
            }
            // cout<<it.first<<"->"<<it.second<<endl;
        }
        return ans;
    }
};