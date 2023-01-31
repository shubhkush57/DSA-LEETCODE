class Solution {
public:
    int solve(vector<pair<int,int>>&v,int prev,int i,vector<vector<int>>&dp1){
        int n = v.size();
        if(i >=n){
            return 0;
        }
        if(dp1[prev][i] != -1){
            return dp1[prev][i];
        }
        int notchoose = solve(v,prev,i+1,dp1);
        int choose = 0;
        if(v[i].first == v[prev].first){
            choose = v[i].second+solve(v,i,i+1,dp1);
        }
        else if(v[i].first > v[prev].first){
            if(v[i].second > v[prev].second){
                choose = v[i].second+solve(v,i,i+1,dp1);
            }
        }
        return dp1[prev][i] = max(choose,notchoose);
    }
    int solve1(vector<pair<int,int>>&v,int prev,int i,vector<vector<int>>&dp2){
        int n = v.size();
        if(i >= n){
            return 0;
        }
        if(dp2[prev][i] != -1){
            return dp2[prev][i];
        }
        int notchoose = solve1(v,prev,i+1,dp2);
        int choose = 0;
        if(v[i].second == v[prev].second){
            choose = v[i].first +  solve1(v,i,i+1,dp2);
        }
        else if(v[i].second > v[prev].second){
            choose = v[i].first + solve1(v,i,i+1,dp2);
        }
        return dp2[prev][i] = max(notchoose,choose);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>>v;
        vector<pair<int,int>>v1;
        vector<vector<int>>dp1(n+1,vector<int>(n+1,-1));
        vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));

        for(int i = 0;i<n;i++){
            v.push_back({ages[i],scores[i]});
            v1.push_back({scores[i],ages[i]});
        }
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        int i = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = max(ans,v[i].second+solve(v,i,i+1,dp1));
        }
        for(int i = 0;i<n;i++){
            ans = max(ans,v1[i].first + solve1(v1,i,i+1,dp2));
        }
        
        return ans;
    }
};