//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[1001][1001];
    int solve(string &s1,string &s2,int i,int j){
        int n = s1.size();
        if(i>=n || j>=n)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j]){
            ans = 1+solve(s1,s2,i+1,j+1);
        }
        else{
            ans = max({ans,solve(s1,s2,i+1,j),solve(s1,s2,i,j+1)});
        }
        return dp[i][j] = ans;
    }
    int minimumNumberOfDeletions(string s) { 
        // code here
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        return n-solve(s,s1,0,0);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends