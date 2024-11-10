class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto it: s){
            if(it == '(' || it == '[' || it == '{')stk.push(it);
            else if(it == ')'){
                if(stk.empty() || stk.top() != '(')return false;
                stk.pop();
            }
            else if(it == ']'){
                if(stk.empty() || stk.top() != '[')return false;
                stk.pop();
            }
            else{
                if(stk.empty() || stk.top() != '{')return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};