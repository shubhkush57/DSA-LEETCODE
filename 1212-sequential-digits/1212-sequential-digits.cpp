class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i = 1;i<=8;i++){
            int val = i,count = i+1;
            while(val<=high && count<=9){
                val = val*10+count;
                if(val>= low && val<=high){
                    ans.push_back(val);
                }
                count++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};