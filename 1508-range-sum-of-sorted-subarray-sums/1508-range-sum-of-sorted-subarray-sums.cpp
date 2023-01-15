class Solution {
public:
    int arr[500500];
    const int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int siz = (n*(n+1))/2;
        // memset(arr,siz,0);
        int k = 0;
        for(int i = 0;i<n;i++){
            long long sum = 0;
            for(int j = i;j<n;j++){
                sum = (sum%mod +nums[j]%mod)%mod;
                arr[k] = sum;
                // cout<<arr[k]<<endl;
                k++;
            }
        }
        sort(arr,arr+siz);
        int ans = 0;
        for(int i = left-1;i<right;i++){
            ans = (ans%mod+arr[i]%mod)%mod;
        }
        return ans%mod;
    }
};