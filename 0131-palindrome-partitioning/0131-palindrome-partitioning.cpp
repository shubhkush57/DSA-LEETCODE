class Solution {
public:
    bool isPalind(string &s,int start,int end){
        int n = s.size();
        while(start<end){
            if(s[start] != s[end])return false;
            start++;end--;
        }
        return true;
    }
    void backtrack(string &s, vector<vector<string>>&ans,vector<string>&re,int start){
        int n = s.size();
        if(start>=n){
            if(re.size()>0){
                ans.push_back(re);
            }
            return;
        }

        for(int i = start;i<n;i++){
            if(isPalind(s,start,i)){
                re.push_back(s.substr(start,i-start+1));
                backtrack(s,ans,re,i+1);
                re.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> re;
        backtrack(s,ans,re,0);
        return ans;
    }
};