class Solution {
public:
    bool solve(string &s){
        int l=0,r=0;
        int star=0;
        for(auto it:s)
        {
            if(it=='(')l++;
            else if(it==')')r++;
            else star++;
            if(r>l+star)return false;
        }
        bool f1= (l+star>=r);
        l=0;
        r=0;
        star=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(')l++;
            else if(s[i]==')')r++;
            else star++;

            if(l>r+star)return false;
        }
        bool f2=(r+star>=l);
        return (f1 and f2);
    }
    bool canBeValid(string s, string locked) {
        string news = s;
        int n = s.size();
        if(n%2)return false;
        for(int i = 0;i<n;i++){
            if(locked[i] == '0'){
                news[i] = '*';
            }
        }
        cout<<news<<endl;
        return solve(news);
    }
};