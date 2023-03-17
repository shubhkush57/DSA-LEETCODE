class Solution {
public:
   
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        
        vector<int>tar;
        for(int i = 0;i<n;i++){
            if( i == 0){
                tar.push_back(target[i]);
            }
            else if(target[i] != tar.back()){
                tar.push_back(target[i]);
            }
        }
        n  = tar.size();
        if(n == 1){
            return target[0];
        }
        int prev_min = 0;
        int ans = 0;
        for(int i = 0;i<tar.size();i++){
            if(i == 0){
                if(tar[i]>tar[i+1]){
                    ans += tar[i]-prev_min;
                }
            }
            else if(i == n-1){
                if(tar[i] > tar[i-1]){
                    ans += tar[i]-prev_min;
                }
            }
            else{
                if(tar[i]>tar[i-1] && tar[i]> tar[i+1]){
                    ans += tar[i]-prev_min;
                }
                else if(tar[i] < tar[i-1] && tar[i] < tar[i+1]){
                    prev_min = tar[i];
                }
                // else if(target[i] > target[i-1] && target[i] >= target[i+1]){
                //     ans += target[i]-prev_min;
                // }
                // else if(target[i] >= target[i-1] && target[i] > target[i+1]){
                //     ans += target[i]-prev_min;
                // }
                // else if(target[i] <= target[i-1] && target[i] < target[i+1]){
                //     prev_min = target[i];
                // }
                // else if(target[i] < target[i-1] && target[i] <= target[i+1]){
                //     prev_min = target[i];
                // }
            }
        }
        return ans;
    }
};