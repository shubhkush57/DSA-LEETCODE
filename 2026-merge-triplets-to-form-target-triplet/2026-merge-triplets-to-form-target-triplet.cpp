class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int>comp(3,0);
        for(int i = 0;i<n;i++){
            if(triplets[i][0]> target[0] || triplets[i][1]> target[1] || triplets[i][2] > target[2])continue;
            for(int j =0;j<=2;j++){
                comp[j] = max(comp[j],triplets[i][j]);
            }
        }
        // cout<<comp[0]<<comp[1]<<comp[2]<<endl;
        return comp == target;
        
    }
};