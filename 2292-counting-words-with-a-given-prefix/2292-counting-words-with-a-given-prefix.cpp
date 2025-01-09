class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans =0;
        int n = pref.size();
        for(auto it: words){
            int siz = it.size();
            if(siz>=n){
                string s = it.substr(0,n);
                if(s == pref)ans++;
            }
        }
        return ans;
    }
};