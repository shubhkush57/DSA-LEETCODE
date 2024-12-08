class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<int>maxv;
        priority_queue<int>pq;
        for(int i = n-1;i>=0;i--){
            pq.push(events[i][2]);
            maxv.push_back(pq.top());
        }
        reverse(maxv.begin(),maxv.end());
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            // go and search for the non overlapping interval in the right of it
            ans = max(ans,events[i][2]);
            int start = i+1;
            int end = n-1;
            int temp = -1;
            while(start<=end){
                // first non overlapping intrval index
                int mid = start+(end -start)/2;
                if(events[mid][0] > events[i][1]){
                    temp = mid;
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            if(temp != -1){
                ans = max(ans,events[i][2]+maxv[temp]);
            }
        }
        return ans;
    }
};