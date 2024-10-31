class Solution {
public:
    #define int2  long long
    int2 dp[101][101];
    int2 solve(vector<int>&robot,vector<vector<int>>&factory,int ri,int fi){
        int n = robot.size();
        int m = factory.size();
        if(ri>=n){
            return 0;
        }
        if(fi>=m){
            return 1e12;
        }
        if(dp[ri][fi]!= -1)return dp[ri][fi];
        int2 ans = solve(robot,factory,ri,fi+1);
        // we have factory index...
        int pos = factory[fi][0], li = factory[fi][1];
        int2 totalDis = 0;
        for(int i = ri;i<n && li>0 ; i++){
            totalDis += (int2)abs(robot[i]-pos);
            ans = min(ans,totalDis+solve(robot,factory,i+1,fi+1));
            li--;
        }
        return dp[ri][fi] = ans;

    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        memset(dp,-1,sizeof(dp));
        int2 ans = solve(robot,factory,0,0);
        return ans;
    }
};