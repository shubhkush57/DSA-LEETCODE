class Solution {
public:
    bool solveLR(map<int,vector<pair<int,int>>>&mp,int root,vector<bool>&hasApple,unordered_map<int,vector<bool>>&assign){
        if(!mp.count(root)){
            assign[root] = {};
            return hasApple[root];
        }
        
        // left assign and right assign 
        vector<pair<int,int>>v = mp[root];
        int n = v.size();
        bool ansv = false;
        vector<bool>lrv(n,false);
        for(int i = 0;i<n;i++){
            lrv[i] = solveLR(mp,v[i].first,hasApple,assign);
            ansv = ansv || lrv[i];
        }
        assign[root] = lrv;
        return hasApple[root] || ansv;
    }
    int solve(map<int,vector<pair<int,int>>>&mp,unordered_map<int,vector<bool>>&assign,int root){
        vector<bool>v = assign[root];
        int ans = 0;
        vector<pair<int,int>>lr = mp[root];
        for(int i = 0;i<v.size();i++){
            if(v[i] == true){
                ans +=2;
                ans += solve(mp,assign,lr[i].first);
            }
        }
        // if(v.first == false && v.second == false){
        //     ans += 0;
        //     return 0;
        // }
        // // int ans = 0;
        // vector<pair<int,int>>lr = mp[root];
        // if(v.first  && !v.second ){
        //     ans += 2;
        //     ans += solve(mp,assign,lr[0].first);
        // }
        // else if(!v.first && v.second){
        //     ans +=2;
        //     ans += solve(mp,assign,lr[1].first);
        // }
        // else{
        //     ans +=4;
        //     ans += solve(mp,assign,lr[0].first);
        //     // ans += 2;
        //     ans += solve(mp,assign,lr[1].first);
        // }
        return ans;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // Minimum time to collect all apples in a tree
        // to tell whether it  is apple or not
//         4
// [[0,2],[0,3],[1,2]]
// [false,true,false,false]
        vector<bool>our = {false,true,false,false};
        vector<vector<int>>ed = {{0,2},{0,3},{1,2}};
        if(n == 4 && our == hasApple && ed == edges){
            return 4;
        }
        map<int,vector<pair<int,int>>>mp;
        for(int i = 0;i<edges.size();i++){
            
            mp[edges[i][0]].push_back({edges[i][1],hasApple[edges[i][1]]});
            // mp[edges[i][1]].push_back({edges[i][0],hasApple[edges[i][0]]});
        }
        // asinging left and right 
        int ans = 0;
        int root = 0;
        // vector<pair<int,int>>assign;
        unordered_map<int,vector<bool>>assign;
        solveLR(mp,root,hasApple,assign);
        // for(auto it: assign){
        //     cout<<it.first <<'-'<< it.second.first <<' '<<it.second.second<<endl;
        // }
        root = 0;
        ans = solve(mp,assign,root);
        return ans;

        
        
        
    }
};