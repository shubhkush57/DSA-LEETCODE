class Solution {
public:
    void solve(map<int,vector<int>>&mp,vector<int>&nodecounter,int i){
        if(!mp.count(i)){
            return;
        }
        for(auto it: mp[i]){
            solve(mp,nodecounter,it);
            nodecounter[i] += nodecounter[it];
        }
        return;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        // step 1: make a map
        // step 2: make the node counter
        // step 3: make map which counts the nodepoducts and thier count
        map<int,vector<int>>mp;
        int n = parents.size();
        for(int i =0;i<n;i++){
            mp[parents[i]].push_back(i); // 
            /// -1 -> 0
            // 0-> 2,4
             /// and so on
        }
        vector<int>nodecounter(n,1);
        int i = 0; //we will be starting from the node 0 and counter the node attach to each node
        solve(mp,nodecounter,i);
        // we have attached to every node just left is to remove and check for the product and store them into an amp
        long long pro = 1;
        long long ans = 1;
        unordered_map<long long,long long > counter;
        for(int i = 0;i<n;i++){
            if(i == 0){
                long long ourpro = 1;
                for(auto it: mp[0]){
                    ourpro = ourpro* (long long)nodecounter[it];
                }
                counter[ourpro]++;
                if(pro <= ourpro){
                    pro = ourpro;
                    ans = counter[ourpro];
                }
            }
            else if(!mp.count(i)){
                long long ourpro = nodecounter[0]-1;
                counter[ourpro]++;
                if(pro<=ourpro){
                    pro = ourpro;
                    ans = counter[ourpro];
                }
            }
            else{
                long long ourpro = 1;
                for(auto it: mp[i]){
                    ourpro = ourpro* (long long)nodecounter[it];
                }
                ourpro = ourpro*(long long)(nodecounter[0]-nodecounter[i]);
                counter[ourpro]++;
                if(pro <= ourpro){
                    pro = ourpro;
                    ans = counter[ourpro];
                }
            }
        }
        return ans;
    }
};