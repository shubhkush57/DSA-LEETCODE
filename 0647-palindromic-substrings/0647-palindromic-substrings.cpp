class Solution {
public:
    int solve(string &s,int left, int right){
        int n = s.size();
        int ans = 0;
        while(left>=0 && right<n && s[left] == s[right]){
            left--;
            right++;
            ans++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        // middle strach
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += solve(s,i,i);
            ans += solve(s,i,i+1);
        }
        return ans;
    }
};