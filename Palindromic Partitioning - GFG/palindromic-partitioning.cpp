//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[505];
    bool isPal(string &str,int s,int e){
        while(s<e){
            if(str[s] != str[e])return false;
            s++;
            e--;
        }
        return true;
    }
    int solve(string &str,int i){
        int n = str.size();
        if(i>=n)return 0;
        if(dp[i] != -1)return dp[i];
        int ans = INT_MAX;
        for(int j = i;j<n;j++){
            if(isPal(str,i,j)){
                ans = min(ans,1+solve(str,j+1));
            }
        }
        return dp[i] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(str,0)-1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends