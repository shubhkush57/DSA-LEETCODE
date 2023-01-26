class Solution {
public:
    static bool comp(pair<long long,long long>&p1,pair<long long,long long>&p2){
        if(p1.first > p2.first){
            return true;
        }
        else if(p1.first == p2.first){
            return p1.second< p2.second;
        }
        return false;
    }
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long>v(n,0L);
        for(int i = 0;i<n;i++){
            v[edges[i]] +=  (long long)i;
        }
        vector<pair<long long,long long>>mp;
        for(int i = 0;i<n;i++){
            mp.push_back({v[i],i});
        }
        sort(mp.begin(),mp.end(),comp);
        return mp[0].second;
    }
};