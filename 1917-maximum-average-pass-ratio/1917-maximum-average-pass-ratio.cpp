class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>>pq;
        int n = classes.size();
        for(int i = 0;i<n;i++){
            double avg_before = ((double)classes[i][0])/classes[i][1];
            double avg_after =  ((double)classes[i][0]+1)/(classes[i][1]+1);
            double diff = avg_after-avg_before;
            pq.push({diff,i});
        }
        while(extraStudents>0){
            auto i = pq.top().second;
            pq.pop();
            classes[i][0]+=1;
            classes[i][1] += 1;
            double avg_before = ((double)classes[i][0])/classes[i][1];
            double avg_after =  ((double)classes[i][0]+1)/(classes[i][1]+1);
            double diff = avg_after-avg_before;
            pq.push({diff,i});

            extraStudents--;
        }
        double avg = 0;
        for(int i = 0;i<n;i++){
            avg += ((double)classes[i][0]/classes[i][1]);
        }
        return avg/n;
    }
};