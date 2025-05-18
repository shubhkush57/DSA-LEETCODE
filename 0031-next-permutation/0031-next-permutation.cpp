class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next lexicographical order arrangement of 
        // nums[i]<nums[i+1]
        // from the back find the number which is greater than nums say index j element
        // now swap nums[i],nums[j]
        // and sort the elements from begin()+i,end();
        int n= nums.size();
        int ind1 = -1;
        for(int i = n-1;i>=0;i--){
            if(i != n-1){
                if(nums[i]<nums[i+1]){
                    ind1 = i;
                    break;
                }
            }
        }
        if(ind1 == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int ind2= -1;
        for(int i = n-1;i> ind1;i--){
            if(nums[i] > nums[ind1]){
                ind2 = i;
                break;
            }
        }
        cout<<ind1<<' '<<ind2<<endl;
        swap(nums[ind1],nums[ind2]);
        // cout<<nums[0]<<' '<<nums[1]<<' '<<nums[2]<<endl;
        sort(nums.begin()+ind1+1,nums.end());
        return;
    }
};