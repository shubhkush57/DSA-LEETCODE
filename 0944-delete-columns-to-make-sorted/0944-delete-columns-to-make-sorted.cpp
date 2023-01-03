class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n= strs.size();
        int ans = 0;
        int t= strs[0].size();
        for(int i= 0;i<t;i++){
            char temp = strs[0][i];
            for(int j = 1;j<n;j++){
                if(strs[j][i] >= temp){
                    temp = strs[j][i];
                }
                else{
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};