class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        return;
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key) == false){
            return "";
        }
        if(timestamp < mp[key][0].first){
            return "";
        }
        // vector<pair<int,string>>v = mp[key];
        int n = mp[key].size();
        int start= 0;
        int end = n-1;
        int ans = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mp[key][mid].first <=timestamp){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        if(ans == -1){
            return "";
        }
        return mp[key][ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */