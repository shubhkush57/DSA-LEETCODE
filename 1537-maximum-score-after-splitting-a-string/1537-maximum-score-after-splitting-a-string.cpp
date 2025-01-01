class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int totalZeros = 0;
        for(auto it: s){
            if(it == '0')totalZeros++;
        }
        int ans = 0;
        int zero = 0;
        for(int i = 0;i<n-1;i++){
            zero += s[i]=='0'?1:0;
            totalZeros -= s[i] == '0'?1:0;
            int ones = n-(i+1)-totalZeros;
            ans = max(ans,ones+zero);
        }
        

        return ans;
    }
};