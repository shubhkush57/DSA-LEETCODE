class Solution {
public:
    bool isPossible(string &s,string &t,int maxCost,int siz){
        int n = s.size();
        int cost = 0;
        int i = 0;
        int j = 0;
        for(j = 0;j<siz;j++){
            cost += abs(s[j]-t[j]);
        }
        if(cost <=maxCost){
            return true;
        }
        while(j<n && i<= j && i<n){
            cost -= abs(s[i]-t[i]);
            cost += abs(s[j]-t[j]);
            if(cost <= maxCost){
                return true;
            }
            i++;j++;
        }
        return cost <= maxCost;
    }
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        int start = 0;
        int end = n;
        while(start<=end){
            int siz = start+(end-start)/2;
            if(isPossible(s,t,maxCost,siz)){
                ans = siz;
                start= siz+1;
            }
            else{
                end = siz-1;
            }
        }
        return ans;
    }
};