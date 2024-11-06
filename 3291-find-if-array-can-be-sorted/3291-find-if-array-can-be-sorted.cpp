class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(nums.begin(),nums.end());
        sort(v.begin(),v.end());
        int j = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        int setBits = __builtin_popcount(nums[0]);
        pq.push(nums[0]);
        for(int i = 1;i<n;i++){
            if(setBits == __builtin_popcount(nums[i])){
                pq.push(nums[i]);
            }
            else{
                while(!pq.empty() && j<n){
                    if(pq.top() != v[j]){
                        return false;
                    }
                    j++;
                    pq.pop();
                }
                setBits = __builtin_popcount(nums[i]);
                pq.push(nums[i]);

            }
        }
        return true;
        // 
    }
};