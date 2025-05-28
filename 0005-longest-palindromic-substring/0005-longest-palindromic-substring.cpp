class Solution {
public:

    string longestPalindrome(string s) {
        // how do  
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        solve(s,0,n-1,dp);
        int ansSiz = 0,start = -1,end=-1;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                bool isPal = dp[i][j];
                if(isPal){
                    int len = j-i+1;
                    if(len>ansSiz){
                        start  = i,end = j;
                        ansSiz = len;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
    bool solve(string &s,int i,int j,vector<vector<int>>&dp){
        int n = s.size();
        if(i>j || j<0 || i>=n)return true;
        if(dp[i][j] != -1)return dp[i][j];
        if(i+1<=j){
            solve(s,i+1,j,dp);
        }
        if(i<=j-1){
            solve(s,i,j-1,dp);
        }
        return dp[i][j] = (s[i] == s[j]) && solve(s,i+1,j-1,dp);
        
    }
};