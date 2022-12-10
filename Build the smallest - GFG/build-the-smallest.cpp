//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string nums, int k)
{
    //code here.
    //code here.
    string ans="";
    for(int i=0;i<nums.size();i++){
        if(ans.size()==0){
            //We need to push only
            ans.push_back(nums[i]);
        }
        else{
            //Means we can check and if avaialable erase
            while(k>0 && ans.size()>0 && ans.back()>nums[i]){
                ans.pop_back();
                k--;
            }
            ans.push_back(nums[i]);
        }
    }
    while(k>0 && ans.size()>0){
        ans.pop_back();
    }
    while(ans.size()>0 && ans.front()=='0'){
        ans.erase(ans.begin());
    }
    if(ans.size()==0)ans+="0";
    return ans;
    
}