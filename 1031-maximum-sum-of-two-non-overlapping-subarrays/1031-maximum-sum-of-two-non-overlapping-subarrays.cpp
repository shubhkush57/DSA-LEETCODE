class Solution {
public:
#define pp pair<int,int>
#define int2 long long int
#define minHeap priority_queue<pp,vector<pp>,greater<pp>>
#define sec second
#define fi  first
#define umapset unordered_map<int,set<int>>
#define repin for(int i = 0;i<n;i++)
#define numsiz int n = nums.size()
#define rev vector<int>
    vector<rev> returnsum(rev &nums,int fl){
        numsiz;
        vector<rev> v1;
         int i = 0,j = 0,sum =0;
        for(j = 0;j<fl;j++){
            sum += nums[j];
        }
        v1.push_back({0,j-1,sum});
        while(j<n){
            sum += nums[j];
            sum -= nums[i];
            i++;
            v1.push_back({i,j,sum});
            j++;
        }
        // for(auto it: v1){
        //     cout<<it[0]<<' '<<it[1]<<' '<<it[2]<<endl;
        // }
        return v1;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int fl, int sl) {
        numsiz;
        vector<rev> v1 = returnsum(nums,fl);
        vector<rev> v2 = returnsum (nums,sl);  
        n = v2.size();
        rev pvmaxsum(n);
        rev pxmaxsum(n);
        for(int i = n-1;i>=0;i--){
            if(i == n-1){
                pvmaxsum[i] = v2[i][2];
            }
            else{
                pvmaxsum[i] = max(pvmaxsum[i+1],v2[i][2]);
            }
        }
        
        for(int i = 0;i<n;i++){
            if(i == 0){
                pxmaxsum[i] = v2[i][2];
            }
            else{
                pxmaxsum[i] = max(pxmaxsum[i-1],v2[i][2]);
            }
        }
        // repin{
        //     cout<<pxmaxsum[i]<<' '<<pvmaxsum[i]<<endl;
        // }
        int ans = 0;
        for(int i = 0;i<v1.size();i++){
            int f = v1[i][0];
            int l = v1[i][1];
            int temp = v1[i][2];
            // serarch for the greater value in the right which is just smaller than f
            int start = 0;
            int end = n-1;
            int indx1 = -1,indx2 = -1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(v2[mid][1]<f){
                    indx1 = mid;
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            start = 0;end = n-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(v2[mid][0]>l){
                    indx2 = mid;
                    end = mid-1;
                }
                else{
                    start= mid+1;
                }
            }
            // cout<<indx1<<' '<<indx2<<endl;
            if(indx1 != -1 && indx2 != -1){
                temp += max(pxmaxsum[indx1],pvmaxsum[indx2]);
                ans = max(ans,temp);
            }
            else if(indx1 == -1 && indx2 != -1){
                temp += pvmaxsum[indx2];
                ans = max(ans,temp);
            }
            else if(indx1 != -1 && indx2 == -1){
                temp += pxmaxsum[indx1];
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};