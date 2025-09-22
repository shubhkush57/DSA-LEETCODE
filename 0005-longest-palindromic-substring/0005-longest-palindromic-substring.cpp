class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0;i<n;i++){
            string even = palSubStr(s,i,i+1);
            string odd = palSubStr(s,i,i);
            if(even.size()<odd.size()){
                even = odd;
            }
            if(ans.size()< even.size()){
                ans = even;
            }
        }

        return ans;
    }
    string palSubStr(string &s,int i,int j){
        int n = s.size();
        string ans = "";
        if(i == j){
            ans.push_back(s[i]);
            i--,j++;
        }
        string left = "";
        while(i>=0 && j<n){
            if(s[i] != s[j])break;
            ans.push_back(s[j]);
            left.push_back(s[i]);
            i--,j++;
        }
        reverse(left.begin(),left.end());
        return left+ans;
    }
};