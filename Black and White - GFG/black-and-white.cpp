//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{
    // write code here
    long long mod=1000000000+7;
    long long total=(long long)(m*n);
    total=total*(total-1);
    long long ans=0;
    for(int r=1;r<=n;r++){
        for(int c=1;c<=m;c++){
            if(r+1<=n && c+2<=m){ans++;}
            if(r+1<=n && c-2>0){ans++;}
            if(r-1>0 && c+2<=m){ans++;}
            if(r-1>0 && c-2>0){ans++;}
            if(r+2<=n && c+1<=m){ans++;}
            if(r+2<=n && c-1>0){ans++;}
            if(r-2>0 && c+1<=m){ans++;}
            if(r-2>0 && c-1>0){ans++;}
        }
    }
    return (total-ans)%mod;
}