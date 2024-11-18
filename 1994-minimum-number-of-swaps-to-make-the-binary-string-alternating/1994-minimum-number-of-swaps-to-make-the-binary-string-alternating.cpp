class Solution {
public:
    int solve(string &s,char c){
        // count mislpance characters..
        int misplaced = 0;
        for(auto it: s){
            if(it != c)misplaced++;
            c = (c == '0')?'1':'0';
        }

        return misplaced/2;
    }
    int minSwaps(string s) {
        int n = s.size();
        int z =0, o = 0;
        for(auto it: s) {
            if(it == '0')z++;
            else o++;
        }
        if(abs(z-o)>1)return -1;
        else if(z>o) return solve(s,'0');
        else if(z<o) return solve(s,'1');
        else{
            return min(solve(s,'0'),solve(s,'1'));
        }
        return -1;
    }
};