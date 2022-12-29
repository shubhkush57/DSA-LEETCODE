class Solution {
public:
    // static bool comp(vector<int>&v1, vector<int>&v2){
    //     if(v1[0]<=v2[0]){
    //         return true;
    //     }
    //     return false;
    // }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
        int n = tasks.size();
        vector<vector<int>>tmp = tasks;
        for(int i = 0;i<n;i++){
            tmp[i].push_back(i);
        }
        sort(tmp.begin(),tmp.end()); //sorted according to the upcoming time
        long long start= 0;
        // shortest time first scheduling algorithm
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long ,int>>>pq;
        int i = 0; 
        while(pq.size() != 0 or i< n){
             if(pq.empty()){
                    start = max(start,(long long)tmp[i][0]);
            }
            while(i<n && start>= tmp[i][0]){
                // pushing the two values the processing time and 
                pq.push({tmp[i][1],tmp[i][2]});
                i++;
            }
            
                // we have processing time and index
               
                    long long procTime = pq.top().first;
                    int ind = pq.top().second;
                    pq.pop();
                    // problem here
                    start +=(long long)procTime;
                    ans.push_back(ind);
                
            
            
        }
        // while(!pq.empty()){
        //     int ind  = pq.top().second;
        //     pq.pop();
        //     ans.push_back(tmp[ind][2]);
        // }
        return ans;
        
    }
};