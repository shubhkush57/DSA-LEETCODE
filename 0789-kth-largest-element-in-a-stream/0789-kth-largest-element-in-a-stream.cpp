class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto it: nums){
            add(it);
        }
        
    }
    
    int add(int it) {
        if(pq.size()<k)
        {
            pq.push(it);
        }
        else{
            if(pq.top()<it){
                pq.pop(); pq.push(it);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */