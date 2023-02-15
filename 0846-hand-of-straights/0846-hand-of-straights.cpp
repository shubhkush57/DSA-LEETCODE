class Solution {
public:
    #define pp pair<int,int>
    #define int2 long long int
    
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>mp;
        for(auto it: hand){
            mp[it]++;
        }
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(auto it: mp){
            // cout<<it.first<<' '<<it.second<<endl;
            pq.push({it.first,it.second});
        }
        // consective one
        while(!pq.empty()){
            int count = 0;
            vector<pp>re;
            while(count <groupSize && !pq.empty()){
                count++;
                pp t = pq.top();
                pq.pop();
                t.second = t.second-1;
                
                if(re.size() == 0){
                    re.push_back(t);
                }
                else{
                    // back value of vecor
                    int siz = re.size()-1;
                    int val = re[siz].first;
                    if(t.first != val+1){
                        return false;
                    }
                    re.push_back(t);
                }
            }
            if(count != groupSize){
                return false;
            }
            for(auto it: re){
                if(it.second != 0){
                    pq.push(it);
                }
            }
        }
        return true;
    }
};