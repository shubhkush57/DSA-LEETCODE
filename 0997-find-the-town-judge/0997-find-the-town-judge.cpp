class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() ==0 && n ==1){
            return n;
        }
        map<int,set<int>>mp;
        for(int i = 0;i<trust.size();i++){
            mp[trust[i][1]].insert(trust[i][0]);
        }
        
        // n-1 people who trusts judges
        int j = -1;
        for(auto it: mp){
            if(it.second.size() == n-1){
                if(j == -1){
                    j = it.first;
                }
                else{
                    cout<<1<<endl;
                    return -1;
                }
            }
            
        }
        if(j == -1){
            return -1;
        }
        // now make sure that j trust no body
        for(auto it: mp){
            if(it.second.count(j)){
                cout<<3<<endl;
                return -1;
            }
        }
        // now get the 
        cout<<4<<endl;
        return j;
    }
};