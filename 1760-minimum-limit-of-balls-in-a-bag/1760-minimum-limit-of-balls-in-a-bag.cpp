class Solution {
public:
    bool isPossible(vector<int>&nums,int k,int mid){
        int n = nums.size();
        // if after k operations the greatest ball int the bag is less = mid return true
        for(int i = 0;i<n;i++){
            if(nums[i]> mid){
                if(nums[i]%mid == 0){
                    k -=(nums[i]/mid)-1;
                }
                else{
                    k -= (nums[i]/mid);
                }
            }
        }
        return k>=0;
    }
    int minimumSize(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 1;
        int end = *max_element(nums.begin(),nums.end());
        int ans = end;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(nums,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};