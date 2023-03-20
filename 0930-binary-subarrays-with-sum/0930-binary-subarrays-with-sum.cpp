class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // no of zeros after one.
        int n = nums.size();
        vector<int>z(n,0);
        int ans  = 0;
        int sum = 0;
        int i = 0,j = 0;
        for(i = n-1;i>=0;i--){
            if(nums[i] == 1){
                z[i] = sum;
                sum = 0;
            }
            else{
                z[i] = sum;
                sum++;
            }
        }
        for(auto it: z){
            cout<<it<<' ';
        }
        cout<<endl;
        i = 0,sum = 0;
        while(j<n){
                sum += nums[j];
                while(sum >= goal && i<=j){
                    if(sum > goal && nums[i] == 0){
                        ans += (1+z[j]);
                    }
                    if(sum == goal){
                        ans += 1+z[j];
                    }
                    sum -= nums[i];
                    i++;
                }
            j++;
        }
        return ans;
    }
};