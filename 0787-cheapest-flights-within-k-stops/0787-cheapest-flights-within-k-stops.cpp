class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>>mp;
        int fligh_size = flights.size();
        for(int i = 0;i<fligh_size;i++){
            mp[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        unordered_map<int,int>mp_re; // this map stores the min distace for each node
        queue<pair<int,int>>q;
        q.push({src,0});
        int z = 0;
        while(!q.empty()){
            int t= q.size();
            z++;
            for(int i = 0;i<t;i++){
                int nsrc = q.front().first;
                int nprice= q.front().second;
                q.pop();
                for(auto it: mp[nsrc]){
                    if(!mp_re.count(it.first) || mp_re[it.first] > nprice+it.second){
                        q.push({it.first,nprice+it.second});
                        mp_re[it.first] = nprice+it.second;
                    }
                }
            }
            if(z == k+1){
                break;
            }
        }
        if(mp_re.count(dst)){
            return mp_re[dst];
        }
        return -1;
    }
};