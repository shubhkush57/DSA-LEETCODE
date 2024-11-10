class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // we have to group the ansgram totherth...
        // so we have to take this case into
        unordered_map<string, vector<string>> mp;
        for (auto it : strs) {
            string copied_str = it;
            sort(it.begin(), it.end());
            mp[it].push_back(copied_str);
        }
        vector<vector<string>>ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};