class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        /*
        int i = 0;
        int j = n-1;
        int ans = 0;
        int t = 1;
        while(i<j){
            if(s[i] == '[' && s[j] == ']' ){
                i++;
                j--;
                t = 0;
            }
            else if(s[i] == ']' && s[j] == '['){
                if(t == 0){
                    i++;
                    j--;
                    t = 1;
                }
                else{
                    s[i] =  '[';
                    s[j] = ']';
                    i++;
                    j--;
                    ans++;
                    t= 0;
                }
                
            }
        }
        return ans;
        */
        stack<char>stk;
        int total = 0;
        for(int i = 0;i<n;i++){
            if(stk.empty()){
                stk.push(s[i]);
                if(s[i] == ']'){
                    total++;
                }
            }
            else{
                if(s[i] == '['){
                    stk.push(s[i]);
                }
                else if(s[i] == ']'){
                    if(stk.top() == '['){
                        stk.pop();
                    }
                    else{
                        stk.push(s[i]);
                        total++;
                    }
                }
            }
        }
        // if total odd or even
        if(total%2 != 0){
            return total/2 + 1;
        }
        return total/2;
    }
};