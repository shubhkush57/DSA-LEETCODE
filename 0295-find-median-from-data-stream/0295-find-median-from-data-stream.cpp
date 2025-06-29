class MedianFinder {
public:
    // we have to make the two haps...
    priority_queue<int>maxHeap; // left side of the array...
    priority_queue<int,vector<int>,greater<int>>minHeap; // right side...
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // now have to add the number and the size differnce between two should not increase more than...tow...
        if(maxHeap.size()>0 && maxHeap.top()>num){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        if(maxHeap.size()>minHeap.size()+1){
            int t = maxHeap.top();maxHeap.pop();
            minHeap.push(t);
        }
        else if(minHeap.size()>maxHeap.size()+1){
            int t = minHeap.top();minHeap.pop();
            maxHeap.push(t);
        }
        return;
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            return (minHeap.top()+maxHeap.top())/2.0;
        }
        else if(minHeap.size()>maxHeap.size()){
            return minHeap.top();
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */