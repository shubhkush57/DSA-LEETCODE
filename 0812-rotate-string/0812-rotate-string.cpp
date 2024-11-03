class Solution {
public:
    bool rotateString(string s, string goal) {
        // int n = s.size();
        if(s.size() != goal.size())return false;
        s = s+s;
        int n = s.size();
        int k = goal.size();
        string re ="";
        int i = 0,j =0;
        for(;j<k;j++){
            re.push_back(s[j]);
        }
        if(re == goal){
            return true;
        }
        while(j<n){
            re = re.substr(1,k-1);
            re.push_back(s[j]);
            if(re== goal){
                return true;
            }
            j++;
        }
        return false;
    }
};