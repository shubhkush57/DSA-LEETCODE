class Solution {
public:
    #define pp pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // pick a classes which has the capticty for the maximum change.
        double n = classes.size();
        priority_queue<pp>pq;
        for(int i = 0;i<n;i++){
            pq.push({((double)classes[i][0]+1)/((double)classes[i][1]+1)-((double)classes[i][0])/((double)classes[i][1]),i});
        }
        while(extraStudents>0){
            pp t = pq.top(); pq.pop();
            int indx = t.second;
            classes[indx][0] += 1;
            classes[indx][1] += 1;
            // now take this and remove the things.
            pq.push({((double)classes[indx][0]+1)/((double)classes[indx][1]+1)-((double)classes[indx][0])/((double)classes[indx][1]),indx});
            extraStudents--;
        }
        double ans = 0;
        for(auto it: classes){
            ans += ((double)it[0]/(double)it[1]);
        }

        return ans/n;
    }
};