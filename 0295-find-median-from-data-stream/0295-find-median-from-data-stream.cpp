class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.size() > 0 && num > maxheap.top()){
            minheap.push(num);
        }
        else{
            maxheap.push(num);
        }
        // at any time difference between them should not be greater than one
        if(maxheap.size() > minheap.size() +1){
            int t= maxheap.top();maxheap.pop();
            minheap.push(t);
        }
        else if(minheap.size() > maxheap.size() +1){
            int t = minheap.top();
            minheap.pop();
            maxheap.push(t);
        }
        return;
    }
    
    double findMedian() {
        if(maxheap.size() == minheap.size()){
            return ((double)(minheap.top()) + (double)(maxheap.top()))/2;
        }
        else if(maxheap.size() > minheap.size()){
            return (double)maxheap.top();
        }
        return (double)minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */