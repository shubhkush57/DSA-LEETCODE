class Solution {
public:
#define pp pair<int,int>
#define int2 long long int
#define minHeap priority_queue<pp,vector<pp>,greater<pp>>
#define sec second
#define fi  first
#define umapset unordered_map<int,set<int>>
#define numsiz  int n = nums.size();
#define repin for(int i = 0;i<n;i++)
#define unmapii unordered_map<int,int>
#define unmapci unordered_map<char,int>
#define mapii map<int,int>
#define mapci map<char,int>
#define rev vector<int>
#define repitmap for(auto it: mp)
#define repitv for(auto it: v)
    bool canPlaceFlowers(vector<int>& nums, int n) {
        if(n == 0)return true;
        int siz = nums.size();
        if(siz == 1 ){
            return nums[0] == 0;
        }
        for(int i = 0;i<siz && n!=0;i++){
            if(nums[i] == 0){
                if(i == 0 && i+1 <siz){
                    if(nums[i+1] == 0){
                        n = n-1;
                        nums[i] = 1;
                    }
                }
                else if(i == siz-1 && i-1>=0){
                    if(nums[i-1] == 0){
                        n = n-1;
                        nums[i] = 1;
                    }
                }
                else{
                    if(i-1>=0 && i+1<siz && nums[i-1] == 0 && nums[i+1] == 0){
                        n = n-1;
                        nums[i] = 1;
                    }
                }
            }
        }
        
        return n == 0;
    }
};