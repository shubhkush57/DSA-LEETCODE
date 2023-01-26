class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long sum = 0;
        // map<int,int>mp;
        vector<int>v(n,0);
        int n_siz = roads.size();
        for(int i = 0;i<n_siz;i++){
            v[roads[i][0]]++;
            v[roads[i][1]]++;
        }
        // we want to calcualte total connection of each node
                
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i = 0;i<v.size();i++){
            sum += (long long)v[i] *(long long)n;
            n = n-1;
        }
        return sum;
    }
};