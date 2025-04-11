class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low;i<=high;i++){
            string number = to_string(i);
            if(number.length() %2 ==0){
                int l = number.length()/2;
                int f1 = 0,f2= 0;
                int j = 0;
                while(j<l){
                    f1 += (number[j]-'0');
                    j++;
                }
                while(j<number.length()){
                    f2 += number[j]-'0';
                    j++;
                }
                if(f1 == f2)ans++;
            }
        }
        return ans;
    }
};