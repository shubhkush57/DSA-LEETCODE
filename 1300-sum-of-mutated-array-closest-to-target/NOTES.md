class Solution {
public:
pair<int,int> isPossible(vector<long long>&prefix,long long mid){
// now find the target value which is near to the
}
int findBestValue(vector<int>& arr, int target) {
int n = arr.size();
sort(arr.begin(),arr.end());
vector<long long>prefix(n,0L);
prefix[0] = (long long)arr[0];
for(int i = 1;i<n;i++){
prefix[i] = prefix[i-1]+(long long)arr[i];
}
// long long start = INT_MIN;
// long long end = INT_MAX;
// while(start<=end){
//     long long mid = start+(end-start)/2;
//     if(isPossible)
// }
long long start= 0L;
long long end = (long long)target;
// we have to find the absolute difference
long long ans = INT_MAX;
while(start<=end){
long long mid = start+(end-start)/2;
pair<int,int> temp = isPossible(prefix,arr,mid);
if(temp.first){
ans= min(ans,temp.second);
end= mid-1;
}
else{
start= mid+1;
}
}
return ans;
}
};