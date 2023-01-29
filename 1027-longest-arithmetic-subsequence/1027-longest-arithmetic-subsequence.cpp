class Solution {
public:
//     int bs(vector<int>&v,int val){
//         // we want the elemnt just greater than it
//         int n = v.size();
//         int start = 0;
//         int end = n-1;
//         int ans = -1;
//         while(start<=end){
//             int mid = start+(end-start)/2;
//             if(v[mid] >val){
//                 ans = v[mid];
//                 end = mid-1;
//             }
//             else{
//                 start = mid+1;
//             }
//         }
//         return ans;
        
//     }
    int dp(vector<int>&nums,int i,int diff,vector<vector<int>>&grid,vector<vector<int>>&arr){
        int n = nums.size();
        if(i == n){
            return 0;
        }
        if(arr[i][diff+500] != -1){
            return arr[i][diff+500];
        }
        // int notchoose = dp(nums,i+1,diff,mp,arr);
        int choose = 0;
        // if(mp.count(nums[i]+diff)){
        //     // if we have we need to find the lowest of it
        //     int p = bs(mp[nums[i]+diff],i);
        //     if(p != -1){
        //         choose =  1+dp(nums,p,diff,mp,arr);
        //     }
        // }
        if(grid[i][diff+500] != -1){
            int p = grid[i][diff+500];
            choose= 1+dp(nums,p,diff,grid,arr);
        }
        return arr[i][diff+500] = choose;
    }
    // int solve(vector<int>&nums,int i,int diff,vector<vector<int>>&grid, vector<vector<int>>arr){
    //     int n = nums.size();
    //     return dp(nums,i,diff,grid,arr);
    // }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>grid(n,vector<int>(1002,-1));
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int diff = nums[j] -nums[i];
                // now we have to find the lowst of it
                if(grid[i][diff+500] == -1){
                        grid[i][diff+500] = j;
                }
            }
        }
        int ans = 0;
        vector<vector<int>>arr(n,vector<int>(1002,-1));
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int diff = nums[j]-nums[i];
                // now count the number form j - n-1 w
                if(arr[i][diff+500] != -1){
                    ans = max(ans,arr[i][diff+500]);
                }
                else{
                    int temp = 1 + dp(nums,i,diff,grid,arr);
                    arr[i][diff+500] = temp;
                    ans = max(ans,temp);
                }
                
            }
        }
        return max(1,ans);
    }
};