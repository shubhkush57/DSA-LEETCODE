class Solution {
public:
    bool isPalindrome(string s,int st,int e){
        while(st<=e){
            if(s[st] != s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
            
    }
    void solve(vector<vector<string>>&ans,vector<string>&pp,int i, string s){
        if(i == s.size()){
            ans.push_back(pp);
            return;
        }
        for(int k = i;k<s.size();k++){
            // it is dfs
            if(isPalindrome(s,i,k)){
                pp.push_back(s.substr(i,k-i+1));
                solve(ans,pp,k+1,s);
                pp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        // now take the values of the string
        int i = 0;
        vector<string>pp;
        solve(ans,pp,i,s);
        return ans;
    }
};