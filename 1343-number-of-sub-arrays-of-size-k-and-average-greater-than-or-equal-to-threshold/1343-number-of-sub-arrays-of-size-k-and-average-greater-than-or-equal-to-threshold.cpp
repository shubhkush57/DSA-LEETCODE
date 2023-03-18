class Solution {
public:
    #define pp pair<int,int>
#define int2 long long int
#define minHeap priority_queue<pp,vector<pp>,greater<pp>>
#define sec second
#define fi  first
#define umapset unordered_map<int,set<int>>
#define repin for(int i = 0;i<n;i++)

    

    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int n = arr.size();
        int2 sum  = 0L;
        int i = 0;
        int j = 0;
        int ans = 0;
        for(;j<k;j++){
            sum += arr[j];
        }
        if(sum >= (th*k)){
            ans++;
        }
        while(j<n){
            sum += arr[j];
            sum -= arr[i];
            if(sum >= (th*k)){
            ans++;
        }
            i++;
            j++;
        }
        return ans;
    }
};