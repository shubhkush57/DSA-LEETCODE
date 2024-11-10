class Solution {
public:
    bool isPalindrome(string str) {
        string s = "";
        for(auto it: str){
            if(isalnum(it)){
                s.push_back(tolower(it));
            }
        }
        cout<<s<<endl;
        int i = 0,j = s.size()-1;
        while(i<j){
            if(s[i] != s[j])return false;
            i++,j--;
        }
        return true;
    }
};