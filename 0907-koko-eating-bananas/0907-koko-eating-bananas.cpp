class Solution {
public:
    bool canFinish(vector<int>&piles,int h,int speed){
        int n = piles.size();
        for(auto pile: piles){
            h -= pile/speed;
            if(pile%speed != 0){
                h--;
            }
        }
        return h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = INT_MAX;
        int ans = end;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(canFinish(piles,h,mid)){
                ans = mid;
                end =mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
        
    }
};