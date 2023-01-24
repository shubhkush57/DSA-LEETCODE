class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n = q.size();
        int ss = s.size();
        // regarding each query we have to give the plated betweent the candles
        // modify the given string 
        vector<int>prefix_sum(ss,0);
        vector<int>candlep;
        vector<int>ans;
        if(s[0] == '*'){
            prefix_sum[0]= 1;
        }
        else{
            prefix_sum[0] = 0;
            candlep.push_back(0);
        }
        for(int i = 1;i<ss;i++){
            if(s[i] == '*'){
                prefix_sum[i] += 1+prefix_sum[i-1];
            }
            else{
                prefix_sum[i] += prefix_sum[i-1];
                candlep.push_back(i);
            }
        }
        for(int i = 0;i<n;i++){
            // for each query
            int left = -1;
            int right = -1;
            int lp= q[i][0];
            int rp = q[i][1];
            int start = 0;
            int end = candlep.size()-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(candlep[mid]>=lp){
                    if(candlep[mid] <= rp){
                        left = candlep[mid];
                    }
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            start= 0;
            end = candlep.size()-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(candlep[mid] <= rp){
                    if(candlep[mid] >= lp){
                        right = candlep[mid];
                    }
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            if(left != -1 && right != -1){
                ans.push_back(prefix_sum[right]-prefix_sum[left]);
            }
            else{
                ans.push_back(0);
            }
        }
        
        
        return ans;
    }
};