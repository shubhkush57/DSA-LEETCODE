class Solution {
public:
    int solve(vector<vector<int>>&events,vector<int>&non, vector<vector<int>>&dp,int i,int k){
        int n = events.size();
        if(i>=n || k <=0 || i == -1){
            return 0;
        }
        // we have choosen the interval k
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        int ans = 0;
        int not_choose = solve(events,non,dp,i+1,k);
        ans = max(not_choose,ans);
        int choose = events[i][2]+ solve(events,non,dp,non[i],k-1);
        ans = max(ans,choose);
        return dp[i][k] = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        // maximum k events to addtend only
        // DP + binary search
        int ans = 0;
        int n = events.size();
        sort(events.begin(),events.end());
        // we want's it's next not overlapping interval
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        vector<int>non(n,-1);
        for(int i = 0;i<n;i++){
            int start= i+1;
            int end = n-1;
            int temp = -1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(events[i][1] < events[mid][0]){
                    temp = mid;
                    end= mid-1;
                }
                else{
                    start= mid+1;
                }
            }
            non[i] = temp;
        }
        int i = 0;
        ans = solve(events,non,dp,i,k);
        return ans;
    }
};