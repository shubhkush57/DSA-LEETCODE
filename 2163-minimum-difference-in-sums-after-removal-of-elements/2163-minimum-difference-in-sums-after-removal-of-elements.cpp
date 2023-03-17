class Solution {
public:
    #define int2 long long
    #define maxhp  priority_queue<int>
    #define minhp priority_queue<int,vector<int>,greater<int>>
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int2 ans = LLONG_MAX;
        maxhp maxpq;
        minhp minpq;
        vector<int2>sumsecond(n,0L);
        vector<int2>sumfirst(n,0L);
        int2 sum = 0L;
        for(int i = n-1;i>=0;i--){
            if(minpq.size()<n/3){
                minpq.push(nums[i]);
                sum += nums[i];
                // if(minpq.size() == n/3){
                    sumsecond[i] = sum;
                // }
            }
            else{
                sum += nums[i];
                minpq.push(nums[i]);
                int t = minpq.top();minpq.pop();
                sum -= t;
                sumsecond[i] = sum;
                
            }
        }
        sum = 0L;
        for(int i =0;i<n;i++){
            if(maxpq.size()<n/3){
                maxpq.push(nums[i]);
                sum += nums[i];
                // if(maxpq.size() == n/3){
                    sumfirst[i] =sum;
                // }
            }
            else{
                sum += nums[i];
                maxpq.push(nums[i]);
                int t = maxpq.top();maxpq.pop();
                sum -=t;
                sumfirst[i] = sum;
            }
        }
        // for(int i = 0;i<n;i++){
        //     cout<<sumfirst[i]<<' '<<sumsecond[i]<<endl;
        // }
        for(int i = n/3-1;i<2*(n/3);i++){
            if(i+1<n){
                ans = min(ans,sumfirst[i]-sumsecond[i+1]);

            }
        }
        // reverse(sumfirst.begin(),sumfirst.end());
        // reverse(sumsecond.begin(),sumsecond.end());
        // for(int i = n/3;i<n;i++){
        //     ans = min(ans,sumfirst[i]-sumsecond[i]);
        // }
        return ans;
    }
};