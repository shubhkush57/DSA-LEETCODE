class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long sum = 0;
        map<int,int>mp;
        int n_siz = roads.size();
        for(int i = 0;i<n_siz;i++){
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        // we want to calcualte total connection of each node
        vector<int>v;
        for(auto it: mp){
            v.push_back(it.second);
            cout<<it.second<<endl;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i = 0;i<v.size();i++){
            sum += (long long)v[i] *(long long)n;
            n = n-1;
        }
        return sum;
    }
};