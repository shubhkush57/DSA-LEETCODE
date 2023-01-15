class Solution {
public:
    bool isPossible(long long mid,long long neededApples){
        long long apples = 2*mid*(mid+1)*(2*mid+1);
        return apples >= neededApples;
    }
    long long minimumPerimeter(long long neededApples) {
        long long start = 1;
        long long end = 100000;
        long long ans = 0;
        while(start<=end){
            long long mid = start+(end-start)/2;
            if(isPossible(mid,neededApples)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return 8*ans;
    }
};