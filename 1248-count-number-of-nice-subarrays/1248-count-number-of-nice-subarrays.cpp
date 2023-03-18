class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int>prev_even(n);
        int prev = 0;
        int i = 0;
        for(i = n-1;i>=0;i--){
            if(nums[i]%2 == 0){
                prev_even[i] = prev;
                prev++;
            }
            else{
                prev_even[i] = prev;
                prev = 0;
            }
        }
        // for(auto it: prev_even){
        //     cout<<it<<' ';
        // }
        // cout<<endl;
        i = 0;
        int j = 0;
        int count = 0;
        while(j<n){
            if(count<k){
                if(nums[j]%2 != 0){
                    count++;
                }
                while(count == k){
                    ans += prev_even[j]+1;
                    if(nums[i]%2 != 0){
                        count--;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
        
    }
};