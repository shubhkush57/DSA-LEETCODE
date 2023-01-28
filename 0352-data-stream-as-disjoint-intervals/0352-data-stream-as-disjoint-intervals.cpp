class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        // add the number in the interval
        st.insert(value);
        return;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        int left = -1,right = -1;
        for(int val: st){
            if(left<0){
                left = right = val;
            }
            else if(val == right+1){
                right = val;
            }
            else{
                ans.push_back({left,right});
                left = right = val;
            }
        }
        if(left == -1 && right == -1){
            return {};
        }
        ans.push_back({left,right});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */