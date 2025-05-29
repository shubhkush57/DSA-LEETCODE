class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n= nums.size();
        vector<int>ans;
        int i = 0,j =0;
        for(;j<k;j++){
            while(!dq.empty() && dq.back() < nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
        }
        ans.push_back(dq.front());
        while(j<n){
            if(dq.front() == nums[i])dq.pop_front();
            while(!dq.empty() && dq.back() < nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);

            i++;
            j++;
            ans.push_back(dq.front());
        }
        return ans;
    }
};