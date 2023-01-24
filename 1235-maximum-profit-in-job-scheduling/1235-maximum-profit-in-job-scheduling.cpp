class Solution {
public:
    int solve(vector<vector<int>>&req,vector<int>&nextno,int i,vector<int>&dp){
        if( i == -1 || i>= req.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 0;
        int notchoose = solve(req,nextno,i+1,dp);
        ans = max(ans,notchoose);
        int choose = req[i][2] + solve(req,nextno,nextno[i],dp);
        ans = max(ans,choose);
        return dp[i] = ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>req(n,vector<int>(3));
        for(int i =0;i<n;i++){
            req[i][0] = startTime[i];
            req[i][1] = endTime[i];
            req[i][2] = profit[i];
        }
        sort(req.begin(),req.end());
        vector<int>nextno(n,-1);
        for(int i =0;i<n;i++){
            int temp= -1;
            int start= i+1;
            int end = n-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(req[mid][0] >= req[i][1]){
                    temp = mid;
                    end = mid-1;
                }
                else{
                    start= mid+1;
                }
            }
            nextno[i] = temp;
        }
        vector<int>dp(n+1,-1);
        int j = 0;
        int ans = solve(req,nextno,j,dp);
        return ans;
    }
};