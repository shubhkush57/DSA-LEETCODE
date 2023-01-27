class Solution {
public:
bool solve(vector<int>&nums,int i,int k,unordered_map<int,int>&mp){
int n = nums.size();
if(i == n){
if(k <= 0){
return true;
}
return false;
}
bool notchoose = solve(nums,i+1,k,mp);
bool choose = false;
if(mp.count(nums[i]*nums[i])){
choose = solve(nums,mp[nums[i]*nums[i]],k-1,mp);
}
return notchoose || choose;
}
bool isPossible(vector<int>&nums,int k,unordered_map<int,int>&mp){
// we have to make the subsequence of size k
// having properites as defined
int i =0 ;
int n = nums.size();
return solve(nums,i,k,mp);
}
int longestSquareStreak(vector<int>& nums) {
int n = nums.size();
int ans = -1;
int start = 2;
int end = n;
sort(nums.begin(),nums.end());
unordered_map<int,int>mp;
for(int j = 0;j<n;j++){
mp[nums[j]] = j;
}
while(start<=end){
int mid = start+(end-start)/2;
if(isPossible(nums,mid,mp)){
ans = mid;
start = mid+1;
}
else{
end = mid-1;
}
}
return ans;
}
};