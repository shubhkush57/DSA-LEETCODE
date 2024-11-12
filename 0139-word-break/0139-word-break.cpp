class Solution {
public:
    bool solve(string &s, int i,unordered_map<string,int>&mp,vector<int>&dp){
        // now we have to take the answer.
        int n = s.size();
        if(i>=n)return true;
        if(dp[i] != -1)return dp[i];
        bool ans = false;
        string re = "";
        for(int j = i;j<n;j++){
            re.push_back(s[j]);
            if(mp.count(re)){
                ans = ans or solve(s,j+1,mp,dp);
            }
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n,-1);
        unordered_map<string,int>mp; 
        for(auto it: wordDict){
            mp[it]++;
        }
        return solve(s,0,mp,dp);
    }
};
//
// Backtrack -> BF solution
// optimize it by take the index by partictions -> DP , map use
// second appraoch me -> trie use karna.