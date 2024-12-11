class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 1;
        for(int i = 0;i<n;i++){
            int start = 0;
            int end = i;
            int target = nums[i]-2*k;
            int startIndx = i,endIndx = i;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(nums[mid] >= target){
                    startIndx = mid;
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            ans = max(ans,i-startIndx+1);
            target = nums[i]+2*k;
            start = i,end = n-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(nums[mid]<=target){
                    endIndx = mid;
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            ans = max(ans,endIndx-i+1);
            // ans = max(ans,endIndx-startIndx+1);



            target = nums[i]-k;
            startIndx = i,endIndx = i;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(nums[mid] >= target){
                    startIndx = mid;
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            target = nums[i]+k;
            start = i,end = n-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(nums[mid]<=target){
                    endIndx = mid;
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            ans = max(ans,endIndx-startIndx+1);
            
        }
        return ans;
    }
};