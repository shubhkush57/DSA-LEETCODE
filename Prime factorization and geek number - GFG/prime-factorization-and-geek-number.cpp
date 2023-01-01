//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void primeFactor(int n,unordered_map<int,int>&mp){
        while(n%2 == 0){
            mp[2]++;
            n = n/2;
        }
        for(int i = 3;i<= sqrt(n);i = i+2){
            while(n%i == 0){
                mp[i]++;
                n = n/i;
            }
        }
        if(n > 2){
            mp[n]++;
        }
        return;
    }
    int geekNumber(int N){
        // code here
        
        unordered_map<int,int>mp;
        primeFactor(N,mp);
        for(auto it: mp){
            if(it.second > 1){
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        if(ob.geekNumber(N))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends