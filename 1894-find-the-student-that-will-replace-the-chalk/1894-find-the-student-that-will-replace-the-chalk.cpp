class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n= chalk.size();
        vector<long long>prefix(n,0L);
        prefix[0] = (long long)chalk[0];
        long long sum = chalk[0];
        for(int i = 1;i<n;i++){
            prefix[i] = (long long)chalk[i]+prefix[i-1];
            sum += (long long)chalk[i];
        }
        long long tk = (long long)k%sum;
        int ans = 0;
        int start= 0;
        int end = n-1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            // if(prefix[mid] == tk ){
            //     if(mid == n-1){
            //         ans = 0;
            //         return ans;
            //     }
            //     else{
            //         ans = mid+1;
            //         return ans;
            //     }
            // }
            // else 
            if(prefix[mid] > tk){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};