//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
            int n = nums.size();
            if(i == j){
                if(i+1<n && i-1>=0){
                    return nums[i]*nums[i+1]*nums[i-1];
                }
                else if(i+1 < n && i-1 <0){
                    return nums[i]*nums[i+1];
                }
                else if(i+1 >=n && i-1>=0){
                    return nums[i]*nums[i-1];
                }
                return nums[i];
            }
            if(dp[i][j] !=-1){
                return dp[i][j];
            }
            int ans = 0;
            for(int k = i;k<=j;k++){
                // if  kth ballon to be first bursted then..
                int temp = 0;
                // how you are going to choose 
                if(i-1 >=0 && j+1<n){
                    temp = nums[k]*nums[i-1]*nums[j+1];
                }
                else if(i-1 <0 && j+1<n){
                    temp = nums[k]*nums[j+1];
                }
                else if(i-1>=0 && j+1>=n){
                    temp = nums[k]*nums[i-1];
                }
                else{
                    temp = nums[k];
                }
                ans = max(ans,temp+solve(nums,i,k-1,dp)+solve(nums,k+1,j,dp));
            }
            return dp[i][j] = ans;
            
        }
        int maxCoins(int N, vector <int> &a)
        {
                // write your code here
                int n = a.size();
                int i = 0;
                int j = n-1;
                vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
                int ans = solve(a,i,j,dp);
                return ans;
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends