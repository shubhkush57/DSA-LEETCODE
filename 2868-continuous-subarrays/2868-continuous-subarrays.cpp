class Solution {
public:
    #define int2 long long
    #define pp pair<int,int>
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pp>maxHeap;
        priority_queue<pp,vector<pp>,greater<pp>>minHeap;

        int i = 0,j = 0;
        int2 ans = 0;
        while(j<n){
            minHeap.push({nums[j],j});
            maxHeap.push({nums[j],j});
            while(maxHeap.size() > 0 && minHeap.size() >0 && maxHeap.top().first-minHeap.top().first>2){
                while(minHeap.empty() == false && minHeap.top().second<=i){
                    minHeap.pop();
                }
                while(maxHeap.empty() == false && maxHeap.top().second<=i){
                    maxHeap.pop();
                }
                i++;
            }
            ans += (j-i+1);
            j++;
        }

        return ans;

    }
};