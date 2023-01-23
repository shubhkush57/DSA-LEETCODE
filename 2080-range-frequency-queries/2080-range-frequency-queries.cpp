class RangeFreqQuery {
public:
    unordered_map<int,vector<int>>mp;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        // don't copy the arrry
        int leftp = -1;
        int rightp = -1;
        int start = 0;
        int end = mp[value].size()-1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mp[value][mid]>= left){
                if(mp[value][mid] <= right){
                    leftp = mid;
                }
                end= mid-1;
            }
            else{
                start = mid+1;
            }
        }
        start= 0;
        end = mp[value].size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mp[value][mid] <=right){
                if(mp[value][mid]>=left){
                    rightp = mid;
                }
                start = mid+1;
            }
            else{
                end= mid-1;
            }
        }
        if(leftp != -1 && rightp != -1){
            return rightp-leftp+1;
        }
        return 0;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */