class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count =0;
        while(num2>0){
            count += (num2&1);
            num2 = num2 >>1;
        }
        vector<int>v(30,0);
        for(int i = 0;i<30;i++){
            if((num1 & (1<<i)) > 0){
                v[i] = 1;
            }
            // cout<<v[i]<<' ';
        }
        reverse(v.begin(),v.end());
        // cout<<endl;
        for(int i = 0;i<30;i++){
            if(v[i] ==0 && (30-i-1) < count){
                count--;
                v[i] = 1;
            }
            else if(v[i] == 1 && count>0){
                count--;
                v[i] = 1;
            }
            else{
                v[i] = 0;
            }
        }
        reverse(v.begin(),v.end());
        int ans = 0;
        for(int i = 0;i<30;i++){
            cout<<v[i]<<' ';
            ans += pow(2,i)*v[i];
        }
        cout<<endl;
        return ans;
                
    }
};