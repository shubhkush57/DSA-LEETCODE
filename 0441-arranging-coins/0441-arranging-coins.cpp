class Solution {
public:
    bool isPossible(int mid,int n){
        long long sum  = ((long long)mid*(mid+1))/2;
        if(sum >n){
            return false;
        }
        return true;
    }
    int arrangeCoins(int n) {
        int start = 1;
        int end = n;
        int row = 0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(mid,n)){
                row = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return row;
    }
};