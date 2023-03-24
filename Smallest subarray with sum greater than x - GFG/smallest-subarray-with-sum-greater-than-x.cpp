//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int nums[], int n, int k)
    {
        
        int i = 0,j = 0;
        int ans = n+1;
        int sum = 0;
        while(j<n){
            sum += nums[j];
            while(i<=j && sum>= k+1){
                ans = min(ans,j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return ans;   
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends