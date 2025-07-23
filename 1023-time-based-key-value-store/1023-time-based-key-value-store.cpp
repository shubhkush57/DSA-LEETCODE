class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>db;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        db[key].push_back({timestamp,value});
        return;
    }
    
    string get(string key, int timestamp) {
        int start = 0;
        int end = db[key].size()-1;
        string ans = "";
        while(start<=end){
            int mid = start+(end-start)/2;
            if(db[key][mid].first<=timestamp){
                ans = db[key][mid].second;
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