class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        int n= tasks.size();
        map<int,int>mp;
        for(int i = 0;i<n;i++){
            mp[tasks[i]]++;
        }
        for(auto it: mp){
            int count = it.second;
            if(count == 1){
                return -1;
            }
            else if(count%3 == 0){
                ans += count/3;
            }
            else if(count%3 == 2){
                ans += count/3;
                ans++;
            }
            else if(count%3 == 1){
                // now check for the 2
                if(count>4){
                    count = count-4;
                    ans += count/3;
                    ans += 2;
                }
                else{
                    ans += 2;
                }
            }
        }
        return ans;
    }
};