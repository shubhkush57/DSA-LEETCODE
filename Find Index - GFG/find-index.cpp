//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 

// } Driver Code Ends
class Solution
{
  public:
    vector<int> findIndex(int a[], int n, int key)
    {
        //code here.
        vector<pair<int,int>>pv;
        for(int  i = 0;i<n;i++){
            pv.push_back({a[i],i});
        }
        sort(pv.begin(),pv.end());
        int s = -1;
        int e = -1;
        for(int i =0;i<n;i++){
            if(pv[i].first ==  key && s == -1){
                s = pv[i].second;
            }
            if(s != -1 && pv[i].first == key){
                e = pv[i].second;
            }
        }
        return {s,e};
    }
  
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        vector<int> res;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        res=ob.findIndex(arr, n, key);
        for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
        cout << "\n";
    }
    
    return 0;
}

// } Driver Code Ends