class Solution {
public:
    #define int2 long long
    long long appealSum(string s) {
        int n = s.size();
        // total no of distinct characters present in the all the substrings...
        int2 ans = 0;
        map<char,vector<int>>mp;
        for(int i = 0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        for(int i = n-1;i>=0;i--){
            int2 temp = 0L;
            for(auto& it: mp){
                int p = it.second.size();
                
                // int start = 0;
                // int end = p-1;
                // int location = -1;
                // while(start<=end){
                //     int mid = start+(end-start)/2;
                //     if(it.second[mid]<= i){
                //         location = it.second[mid];
                //         start = mid+1;
                //     }
                //     else{
                //         end = mid-1;
                //     }
                // }
                // if(location != -1){
                //     temp += location+1L;
                // }
                if(p>0)
                temp += (int2)it.second[p-1]+1L;
                if(it.first == s[i]){
                     it.second.pop_back();
                }
                
            }
           
            ans += temp;
        }
        return ans;
    }
};