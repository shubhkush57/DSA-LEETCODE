//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int solve(int n,int w,int val[],int wt[],int i){
        if(i>=n){
            return 0;
        }
        if(dp[i][w]!= -1)return dp[i][w];
        int ans = solve(n,w,val,wt,i+1);
        if(w-wt[i]>=0)
        ans = max(ans,val[i]+solve(n,w-wt[i],val,wt,i));
        return dp[i][w] = ans;
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(N,W,val,wt,0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends