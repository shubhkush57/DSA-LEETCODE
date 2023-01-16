class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        vector<vector<int>>ans;
        int n = intervals.size();
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(flag == false){
                if(ni[1]<intervals[i][0]){
                    ans.push_back(ni);
                    ans.push_back(intervals[i]);
                    flag = true;
                }
                else if(ni[1] == intervals[i][0]){
                    intervals[i][0]= min(ni[0],intervals[i][0]);
                    intervals[i][1] = max(ni[1],intervals[i][1]);
                    ans.push_back(intervals[i]);
                    flag = true;
                }
                else if(ni[1] >=intervals[i][0] && ni[1] <=intervals[i][1]){
                    intervals[i][0] = min(ni[0],intervals[i][0]);
                    intervals[i][1] = max(ni[1],intervals[i][1]);
                    ans.push_back(intervals[i]);
                    flag = true;
                }
                else if(ni[0]<= intervals[i][0] && ni[1] >= intervals[i][1]){
                    ans.push_back(ni);
                    flag = true;
                }
                // mainn conditions
                else if(ni[0]>=intervals[i][0] && ni[0] <=intervals[i][1]){
                    intervals[i][0] = min(intervals[i][0],ni[0]);
                    intervals[i][1]= max(intervals[i][1],ni[1]);
                    ans.push_back(intervals[i]);
                    flag = true;
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
            else{
                // we have inserted  the ni now
                int j = ans.size();
                if(intervals[i][0]>=ans[j-1][0] && intervals[i][0]<=ans[j-1][1]){
                    ans[j-1][0] = min(intervals[i][0],ans[j-1][0]);
                    ans[j-1][1] = max(intervals[i][1],ans[j-1][1]);
                    // ans.push_back(intervals[i])
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
            
        }
        if(flag == false){
            ans.push_back(ni);
        }
        return ans;
    }
};