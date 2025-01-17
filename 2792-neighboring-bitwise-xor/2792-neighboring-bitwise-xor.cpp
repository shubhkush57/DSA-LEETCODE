class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int b = 0;
        int n = d.size();
        int prev = b;
        for(int i = 0;i<n;i++){
            int temp = prev ^ d[i];
            prev = temp;
            if( i == n-1 && prev == b){
                return true;
            }
        }
        b = 1;
        prev = b;
        for(int i = 0;i<n;i++){
            int temp = prev ^ d[i];
            prev = temp;
            if( i == n-1 && prev == b){
                return true;
            }
        }
        return false;
    }
};