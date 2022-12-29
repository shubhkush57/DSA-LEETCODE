class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>stk;
        int n = s.size();
        string ans = "";
        for(int i = 0;i<n;i++){
            if(stk.empty() && (s[i] == ')' || s[i] == '(')){
                stk.push({s[i],i});
            }
            else{
                // stk not empty() then we have to get the total 
                if(s[i] == ')'){
                    if(stk.top().first == '('){
                        stk.pop();
                    }
                    else{
                        stk.push({')',i});
                    }
                }
                else if(s[i] == '('){
                    stk.push({'(',i});
                }
            }
        }
        // now taking the values of the terms which remained
        for(int i = n-1;i>=0;i--){
            if((s[i] != '(') && (s[i] != ')')){
                ans.push_back(s[i]);
            }
            else if(stk.size() != 0 && stk.top().second != i){
                ans.push_back(s[i]);
            }
            else if(stk.size() != 0 && stk.top().second == i){
                stk.pop();
            }
            else if(stk.size() == 0){
                ans.push_back(s[i]);
            }
            else{
                stk.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};