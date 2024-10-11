class Solution {

public:

    #define pp pair<int,int>

    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n = times.size();

        vector<vector<int>>v;

        for(int i = 0;i<n;i++){

            v.push_back({times[i][0],times[i][1],i});

        }

        sort(v.begin(),v.end());

        priority_queue<int,vector<int>,greater<int>>pq;

        priority_queue<pp,vector<pp>,greater<pp>>pq1;

        for(int i = 0;i<n;i++)pq.push(i);

        for(auto it: v){

            int indx = it[2],coming_time = it[0],going_time = it[1];

            // now

            while(!pq1.empty() && pq1.top().first <=coming_time){

                pq.push(pq1.top().second);

                pq1.pop();

            }

            if(indx == targetFriend){

                return pq.top();

            }

            pq1.push({going_time,pq.top()});

            pq.pop();

        }

        return -1;

    }

};