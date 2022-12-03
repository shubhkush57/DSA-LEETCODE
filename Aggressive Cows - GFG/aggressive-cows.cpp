//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(vector<int>&stalls,int k,int dis){
        int n = stalls.size(); 
        // dis the minimum distance betweent the two cows that can be there
        int pos = stalls[0];
        k--;
        for(int i = 1;i<n;i++){
            if(stalls[i]-pos >= dis){
                k--;
                pos = stalls[i];
            }
        }
        return k<=0;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code her
        int ans = -1;
        int start = 1;
        sort(stalls.begin(),stalls.end());
        int end = stalls[n-1]-stalls[0];
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(stalls,k,mid)){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends