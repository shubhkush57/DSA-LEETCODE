class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int mayor1 = INT_MAX,vote1 = 0,mayor2 = INT_MAX,vote2 = 0;
        for(auto vote: nums){
            if(vote == mayor1)vote1++;
            else if(vote == mayor2)vote2++;
            else if(vote1 == 0){
                mayor1 = vote; vote1++;
            }
            else if(vote2 == 0){
                mayor2 = vote; vote2++;
            }
            else{
                vote1--,vote2--;
            }
        }
        vote1 = 0,vote2 = 0;
        for(auto vote: nums){
            if(vote == mayor1)vote1++;
            
            if(vote == mayor2)vote2++;
            
        }
        if(vote1>n/3)ans.push_back(mayor1);
        if(vote2>n/3)ans.push_back(mayor2);
        return ans;
        
    }
};