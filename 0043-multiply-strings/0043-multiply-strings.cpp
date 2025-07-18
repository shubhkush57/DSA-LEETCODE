class Solution {
public:
    string addition(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';

        carry = sum / 10;
        result = char((sum % 10) + '0') + result;
    }

    return result;
}
    string multiply(string num1, string num2) {
        int n1 = num1.size(),n2 = num2.size();
        string ans= "";
        reverse(num2.begin(),num2.end());
        reverse(num1.begin(),num1.end());
        int z = 0;
        for(auto ch: num2){
            string res = "";

            int lastRem = 0;
            for(auto it: num1){
                int val = (ch-'0')*(it-'0')+lastRem;
                lastRem = val/10;
                val = val%10;
                res.push_back(val+'0');
            }
            if(lastRem != 0)res.push_back(lastRem+'0');
            reverse(res.begin(),res.end());

            for(int i = 0;i<z;i++){
                res.push_back('0');
            }
            
            ans = addition(ans,res);
            cout<<ans<<endl;
            z++;
        }
        if(ans[0] == '0')return "0";
        return ans;
    }
};