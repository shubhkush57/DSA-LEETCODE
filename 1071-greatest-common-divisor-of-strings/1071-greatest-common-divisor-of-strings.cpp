class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        int t = min(n1,n2);
        string ans = "";
        string temp = "";
        for(int i = 0;i<t;i++){
            temp.push_back(str1[i]);
            int q = temp.size();
            bool flag = true;
            if(n1%q == 0 && n2%q == 0){
                for(int j = 0;j<n1;){
                    for(int k = 0;k<q;k++){
                        if(temp[k] == str1[j]){
                            j++;
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }
                    if(flag == false){
                        break;
                    }
                }
                for(int j = 0;j<n2;){
                    for(int k = 0;k<q;k++){
                        if(temp[k] == str2[j]){
                            j++;
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }
                    if(flag == false){
                        break;
                    }
                }
                if(flag){
                    ans = temp;
                }
            }
        }
        return ans;
    }
};