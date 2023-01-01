//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor( int n){
        // code here
        // we have to return the largest prime factor of a number 
        long long n1 =  n;
        long long ans = -1;
        while(n1%2 == 0){
            ans = max(ans,(long long int)2);
            n1 = n1/2;
        }
        for(long long int j = 3;j<=sqrt(n1); j = j+2){
            while(n1%j == 0){
                n1 = n1/j;
                ans = max(ans,j);
            }
        }
        if(n1 > 2){
            ans = max(ans,n1);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends