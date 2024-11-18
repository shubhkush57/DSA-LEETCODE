class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;

        for(int i = 1;i<=8;i++){
            int val = i;
            int count = i+1;
            while(val<=high && count<=9){
                val = val*10+count;
                if(val<=high && val >=low){
                    ans.push_back(val);
                }
                count++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};