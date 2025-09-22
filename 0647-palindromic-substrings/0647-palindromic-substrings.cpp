class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int even = countPail(s,i,i+1);
            int odd = countPail(s,i,i);
            ans += even+odd;
        }
        return ans;
    }

    int countPail(string &s,int i,int j){
        int ans = 0;
        int n = s.size();
        if(i == j){
            ans++;i--,j++;
        }
        while(i>=0 && j<n){
            if(s[i]!= s[j])break;
            i--;j++;
            ans++;
        }
        return ans;
    }
};