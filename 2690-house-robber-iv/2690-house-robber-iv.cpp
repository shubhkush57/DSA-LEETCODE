class Solution {
public:
    bool isPossible(vector<int>&nums,int k,int mid){
        int n = nums.size();
        int i =0 ;
        for(i = 0;i<n;){
            if(nums[i] <= mid){
                k--;
                i = i+2;
                if(k <=0){
                    return true;
                }
            }
            else{
                i = i+1;
            }
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int end = INT_MAX;
        int ans = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(nums,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start= mid+1;
            }
        }
        return ans;
    }
};