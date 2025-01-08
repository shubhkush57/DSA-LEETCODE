class Solution {
public:
    bool isPrefixAndSuffix(string &s1,string &s2){
        int n = s1.size();
        int m = s2.size();
        if(n>m)return false;
        string pre = s2.substr(0,n);
        // j-i+1 = n
        // m -i  = n;
        // i = m-n
        string suf = s2.substr(m-n,n);
        return pre == s1 && suf == s1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        // we have to see the things 
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j]))ans++;
            }
        }

        return ans;
    }
};