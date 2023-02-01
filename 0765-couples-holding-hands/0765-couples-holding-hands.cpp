class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        // couples n/2;
        map<int,int>mp;
        for(int i = 0;i<n;i++){
            int t = row[i];
            mp[t] = i;
            // mp.insert({row[i],i});
            // cout<<mp[t]<<' '<<i<<endl;
        }
        // for(auto it: mp){
        //     cout<<it.first<<' '<<it.second<<endl;
        // }
        int ans = 0;
        for(int i = 0;i<n;){
            if(row[i]%2 == 0){
                // serch for row[i+1];
                int p = mp[row[i]+1];
                // should be next to 
                if(p != i+1){
                    mp[row[i]+1] = i+1;
                    row[p] = row[i+1];
                    mp[row[p]] = p;
                    ans++;
                }
                
            }
            else{
                // search for i-1;
                int p = mp[row[i]-1];
                if(p != i+1){
                    mp[row[i]-1] = i+1;
                    row[p] = row[i+1];
                    mp[row[p]] = p;
                    ans++;
                }
            }
            i = i+2;
        }
        return ans;
    }
};