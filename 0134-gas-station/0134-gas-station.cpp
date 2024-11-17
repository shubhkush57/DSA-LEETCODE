class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int g = 0;
        int n = gas.size();
        int totalGas = 0;
        for(int i = 0;i<n;i++){
            totalGas += (gas[i]-cost[i]);
            g += (gas[i]-cost[i]);
            if(g<0){
                start = i+1;
                g = 0;
            }
        }
        return totalGas<0?-1:start;
    }
};