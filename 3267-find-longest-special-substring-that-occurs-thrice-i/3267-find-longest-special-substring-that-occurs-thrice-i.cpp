class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int ans = 0;
        for(char ch = 'a';ch<='z';ch++){
            // cout<<ch<<"->"<<endl;
            for(int siz = 1;siz<= n;siz++){
                // now take the string and compare it's value 
                int i = 0; 
                int count = 0;
                while(i<n){
                    int j = i;
                    while(j<n && (s[j] == ch) && ((j-i+1)<=siz)){
                        if(j-i+1 == siz){
                            // cout<<i<<' ';
                            count++;
                        }
                        j++;
                        
                    }
                    i++;
                }
                // cout<<siz<<' '<<count<<endl;
                if(count>=3){
                    ans = max(ans,siz);
                }
            }

        }
        return ans == 0?-1:ans;
    }
};