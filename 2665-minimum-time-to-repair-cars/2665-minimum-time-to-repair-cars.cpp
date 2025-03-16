class Solution {
public:
    #define int2 long long
    bool isPossible(vector<int>&ranks,int cars,int2 mid){
        int n = ranks.size();
        int2 total = 0;
        for(int i = 0;i<n;i++){
            int2 v1 = mid/ranks[i];
            v1 = sqrt(v1);
            total += v1;
        }
        return total >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        sort(ranks.begin(),ranks.end());
        int2 ans = LLONG_MAX;
        int2 start = 0L;
        int2 end = ans;
        while(start<=end){
            int2 mid = start+(end-start)/2;
            if(isPossible(ranks,cars,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};