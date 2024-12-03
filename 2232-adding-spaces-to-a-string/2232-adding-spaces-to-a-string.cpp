class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.size();
        int count = 0;
        int i = 0;
        int j = 0;
        while(i<n){
            if(j< spaces.size() && count == spaces[j]){
                ans.push_back(' ');
                j++;
            }
            ans.push_back(s[i]);
            count++;
            i++;

        }
        return ans;
    }
};