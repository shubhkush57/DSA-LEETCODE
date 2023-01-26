class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<long long>prefix(n,0L);
        prefix[0] = (long long)arr[0];
        for(int i =1 ;i<n;i++){
            prefix[i] = prefix[i-1]+(long long)arr[i];
        }
        if(prefix[n-1] <= target){
            return arr[n-1];
        }
    
        int start = 0;
        int end = arr[n-1];
        int ans = INT_MAX;
        int prev = INT_MAX;
        int abs_diff_min=INT_MAX;
        while(start<=end){
            int mid = start+(end-start)/2;
//             if(isPossible(arr,prefix,target,mid)){
//                 ans = mid;
                
//             }
               // int p = lower_bound(arr.begin(),arr.end(),mid)-arr.begin();
               long long temp_sum = 0;
               // int abs_diff_min=INT_MAX;
               for(int i = 0;i<n;i++){
                   if(arr[i] > mid){
                       temp_sum += (long long)mid;
                   }
                   else{
                       temp_sum += (long long)arr[i];
                   }
               }
               // long long temp_sum = prefix[p]+(n-1-p)*mid;
               // if(temp_sum == (long long)target){
               //     ans = min(ans,mid);
               //     abs_diff_min = 0;
               //     end = mid-1;
               // }
               if(temp_sum >=(long long)target){
                   end = mid-1;
                 if(abs(temp_sum-(long long)target) <abs_diff_min){
                     ans= mid;
                     abs_diff_min=abs(temp_sum-target);
                     
                 }
                 else if(abs(temp_sum-(long long)target) ==abs_diff_min){
                     ans=min(ans,mid);
                     abs_diff_min=abs(temp_sum-target);
                     
                 }
                  
               }
               else{
                    if(abs(temp_sum-(long long)target) <abs_diff_min){
                     ans=mid;
                     abs_diff_min=abs(temp_sum-(long long)target);
                     
                   }
                   else if(abs(temp_sum-(long long)target) ==abs_diff_min){
                     ans=min(ans,mid);
                     abs_diff_min=abs(temp_sum-target);
                     
                 }
                   start = mid+1;
               }
        }
        return ans;
        
    }
};