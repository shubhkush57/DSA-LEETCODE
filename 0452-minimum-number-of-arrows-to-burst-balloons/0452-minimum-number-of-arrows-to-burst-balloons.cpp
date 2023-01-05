class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // no of overlap find
        sort(points.begin(),points.end());
        int overlap = 0;
        int n = points.size();
        for(int i = 1;i<n;i++){
            if(points[i][0] <= points[i-1][1]){
                overlap++;
                points[i][1] = min(points[i][1],points[i-1][1]);
            }
        }
        return n - overlap;
    }
};