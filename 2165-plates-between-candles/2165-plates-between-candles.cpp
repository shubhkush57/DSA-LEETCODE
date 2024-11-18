class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // let's make prefix array and answer
        int count= 0;
        int n = s.size();
        vector<int>prefix(n,0);
        vector<int>positionsCandles;
        for(int i = 0;i<n;i++){
            if(s[i] == '*')count++;
            else{
                positionsCandles.push_back(i);
            }
            prefix[i] = count;
        }
        // n ow 
        vector<int>ans;
        for(auto it: queries){
            int start = it[0];
            int end = it[1];
            int left = lower_bound(positionsCandles.begin(),positionsCandles.end(),start)-positionsCandles.begin();
            int right = upper_bound(positionsCandles.begin(),positionsCandles.end(),end)-positionsCandles.begin();
            if(left<0 || left>= positionsCandles.size() || right<=0 || right > positionsCandles.size() || (prefix[positionsCandles[right-1]]-prefix[positionsCandles[left]])<0)ans.push_back(0);
            else ans.push_back(prefix[positionsCandles[right-1]]-prefix[positionsCandles[left]]);
         }
        return ans;
    }
};