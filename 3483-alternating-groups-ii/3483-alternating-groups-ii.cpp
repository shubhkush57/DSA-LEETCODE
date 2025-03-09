class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i = 0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int i = 0,j = 0;
        int ans = 0;
        while(j<n){
            bool flag = true;
            while((i-j+1)<k){
                if(colors[i] != colors[i+1]){
                    i++;
                }
                else{
                    flag = false;
                    i++;
                    j = i;
                    break;
                }
            }
            if(i-j+1 ==k)ans++;
            if(flag)
            j++;
            // now we have to do the answer 
        }

        return ans;

        
    }
};