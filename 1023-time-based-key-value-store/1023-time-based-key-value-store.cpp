class TimeMap {
public:
    #define pp pair<int,string>
    unordered_map<string,vector<pp>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        return;
    }
    
    string get(string key, int timestamp) {
        // we have to get teh value of this time stanmp;;
        string ans = "";
        int start = 0;
        int end = mp[key].size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mp[key][mid].first <= timestamp){
                ans = mp[key][mid].second;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */