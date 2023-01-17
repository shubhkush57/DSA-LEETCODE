class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>rev(n);
        for(int i = 0;i<n;i++){
            rev[i].push_back(intervals[i][0]);
            rev[i].push_back(intervals[i][1]);
            rev[i].push_back(i);
        }
        vector<int>ans(n);
        sort(rev.begin(),rev.end());
        for(int i = 0;i<n;i++){
            int tempans = -1;
            int start = i;
            int end = n-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(rev[mid][0] >=rev[i][1]){
                    tempans = rev[mid][2];
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            ans[rev[i][2]] = tempans;
        }
        return ans;
    }
};