class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // window of maximum size having maximum of fruits of 2 types
        unordered_map<int,int>mp;
        int n = fruits.size();
        int ans = 0;
        int j = 0;
        for(int i = 0;i<n;i++){
            mp[fruits[i]]++;
            if(mp.size() <=2){
                ans = max(ans,(i-j+1));
            }
            else{
                // now want to remove the element from the start until 
                while(mp.size() >2 && j<n){
                    mp[fruits[j]]--;
                    if(mp[fruits[j]] == 0){
                        mp.erase(fruits[j]);
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};