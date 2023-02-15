class Solution {
public:
    #define pp pair<int,int>
    #define int2 long long int
    #define minHeap priority_queue<pp,vector<pp>,greater<pp>>
    #define sec second
    #define fi  first
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        int groupSize = k;
        // cout<<n<<endl;
        if(n%k != 0){
            return false;
        }
        unordered_map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        minHeap pq;
        for(auto it: mp){
            // cout<<it.fi<<' '<<it.sec<<endl;
            pq.push(it);
        }
        while(!pq.empty()){
            vector<pp>re;
            int count = 0;
            while(count< groupSize && !pq.empty()){
                count++;
                pp t = pq.top();pq.pop();
                t.sec = t.sec -1;
                if(re.size() == 0){
                    re.push_back(t);
                }
                else{
                    if(t.fi != re.back().first+1){
                        return false;
                    }
                    re.push_back(t);
                }
            }
            if(count != groupSize){
                return false;
            }
            for(auto it: re){
                // cout<<it.first<<' ';
                if(it.sec != 0){
                    pq.push(it);
                }
            }
            // cout<<endl;
        }
        return true;   
    }
};