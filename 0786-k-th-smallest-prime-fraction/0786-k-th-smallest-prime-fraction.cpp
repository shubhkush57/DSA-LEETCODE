class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>>pq;
        int n = arr.size();
        for(int i = 0;i<n-1;i++){
            double t =(double) arr[i];
            for(int j = i+1;j<n;j++){
                pq.push({t/arr[j],{i,j}});
                if(pq.size() >k){
                    pq.pop();
                }
            }
        }
        return {arr[pq.top().second.first],arr[pq.top().second.second]};
        
    }
};