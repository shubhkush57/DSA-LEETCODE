class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // difference array Technique...
        int n = s.size();
        int siz = s.size();
        vector<int>diffArr(n,0);
        // 
        for(auto shift: shifts){
            int s = shift[0];
            int e = shift[1];
            int add = (shift[2] == 0)?-1:1;
            diffArr[s] += add;
            if(e != n-1) diffArr[e+1] -= (add);
        }
        // we have to also take the prefix sum...
        int noOfShifts = 0;
        for(int i = 0;i<n;i++){
            noOfShifts = (noOfShifts+diffArr[i])%26;
            if(noOfShifts<0) noOfShifts += 26;
            s[i] = 'a'+(s[i] - 'a'+noOfShifts) % 26;
        }        
        for(auto it: diffArr){
            cout<<it<<' ';
        }
        return s;

    }
};