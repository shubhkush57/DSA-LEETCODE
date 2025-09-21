class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i= 0;i<n-2;i++){
            if(i !=0 && nums[i] == nums[i-1])continue;
            int j = i+1,k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(j<n && nums[j] == nums[j-1])j++;
                    k--;
                    while(k>=0 && nums[k] == nums[k+1])k--;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }


        return ans;
    }
};