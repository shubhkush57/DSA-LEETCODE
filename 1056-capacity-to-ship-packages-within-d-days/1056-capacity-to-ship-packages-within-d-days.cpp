class Solution {
public:
    bool isPossibleToShip(vector<int>& weights,int cap,int days){
        int n = weights.size();
        int i = 0;
        int currShipWeight = 0;
        while(i<n){
            if(currShipWeight+ weights[i]<= cap){
                currShipWeight += weights[i];
            }
            else{
                days--;
                // 5 cur = 9
                currShipWeight = weights[i];
            }
            i++;
        }
        if(currShipWeight>0)days--;
        return days>=0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int  start = *max_element(weights.begin(),weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);
        int ans = end;
        while(start<=end){
            int mid = start+(end-start)/2;
             if(isPossibleToShip(weights,mid,days)){
                ans = mid;
                end = mid-1;
            }
            else{
                start= mid+1;
            }
        }
        
        return ans;
    }
};