class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // we have to find the lengthe of longest substring without reapri
        unordered_map<char,int>mp;
        int n = s.size();
        int i = 0,j = 0;
        int ans = 0;
        while(j<n){
            mp[s[j]]++;
            while(i<j && mp.size()<(j-i+1)){
                // we can do it.. remove the elemnts fromt eh 
                mp[s[i]]--;
                if(mp[s[i]]== 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};