//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        int i = 0;
        int j = 0;
        if(M != N){
            return false;
        }
        while(i<M && j<N){
            while(i< M && S[i] == '#'){
                i++;
            }
            while(j<N && T[j] == '#'){
                j++;
            }
            // now take the value of the given terms
            if(i>=M && j>= N ){
                return true;
            }
            else if (i>=M || j>=N || S[i] != T[j]){
                return false;
            }
            else if(S[i] == 'A' && i<j){
                return false;
            }
            else if(S[i] == 'B' && i>j){
                return false;
            }
            else{
                i++;
                j++;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends