class Solution {
public: 
    #define int2 long long
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int ans = 0;
        int2 sum = 0;
        priority_queue<pair<int,int>>pq;
        int i = 0,j = 0;
        while(j<n){
            sum +=(int2) runningCosts[j];
            pq.push({chargeTimes[j],j});
            while(pq.empty()== false && (sum*(j-i+1) + pq.top().first > budget)){
                sum -= runningCosts[i];
                while(!pq.empty() && pq.top().second<=i ){
                    pq.pop();
                }
                i++;
            }
            ans = max(ans,(j-i+1));
            j++;


        }
        return ans;
    }
};