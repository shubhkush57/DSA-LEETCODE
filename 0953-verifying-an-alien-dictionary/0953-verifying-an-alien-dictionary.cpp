class Solution {
public:
    static bool comp(string &order,string &s1,string &s2){
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        // if i sort the words according to the order 
        // and if result in not equal then 
        int n = words.size();
        unordered_map<char,int>mp;
        for(int i = 0;i<order.size();i++){
            mp[order[i]] = i;
        }
     
       
        // lets' compare two adj strings
        for(int i = 0;i<n-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int siz = min(s1.size(),s2.size());
            bool flag = false;
            // if first any character is smaller
            for(int j = 0;j<siz;j++){
                if(mp[s1[j]] > mp[s2[j]]){
                    return false;
                }
                else if(mp[s1[j]]< mp[s2[j]]){
                    flag = true;
                    break;
                }
                else{
                    // if both are equal 
                }
            }
            if(flag == false){
                if(s1.size() > s2.size()){
                    return false;
                }
            }
            // if(s1.size() > s2.size()){
            //     return false;
            // }
        }
        return true;
        
    }
};