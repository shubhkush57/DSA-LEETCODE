class Solution {
public:
    int bs(vector<int>&v,int val){
        int n = v.size();
        int start = 0;
        int end = n-1;
        int ans = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(v[mid]>val){
                ans = v[mid];
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
    int dp(vector<int>&arr,int diff,int i,unordered_map<int,vector<int>>&mp,vector<int>&redp){
        int n = arr.size();
        if(i == n){
            return 0;
        }
        if(redp[i] != -1){
            return redp[i];
        }
        // int notchoose = dp(arr,diff,i+1,mp,redp);
        int choose = 0;
        if(mp.count(arr[i]+diff)){
            int p = bs(mp[arr[i]+diff],i);
            if(p !=  -1){
                choose  = 1+ dp(arr,diff,p,mp,redp);
            }
        }
        return redp[i] = choose;
    }
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int,vector<int>>mp;
        vector<int>redp(n,-1);
        for(int i =0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        int ans = 1;
        for(int i = 0;i<n;i++){
            if(redp[i] != -1){
                ans = max(ans,redp[i]);
            }
            else{
                int temp = 1+dp(arr,diff,i,mp,redp);
                ans = max(ans,temp);
                redp[i] = temp;
            }
        }
        return ans;
    }
};