class MedianFinder {
    
    struct compMin{
        bool operator()(int a,int b){
            return a > b;
        }
    };
    
    struct compMax{
        bool operator()(int a,int b){
            return a < b;
        }
    };
    
public:
    /** initialize your data structure here. */
    priority_queue<int,vector<int>,compMin>minHeap;
    priority_queue<int,vector<int>,compMax>maxHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        int maxElement = maxHeap.top();
        maxHeap.pop();
        minHeap.push(maxElement);
        
        if(minHeap.size() > maxHeap.size()){
            int minElement = minHeap.top();
            minHeap.pop();
            maxHeap.push(minElement);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (double) (minHeap.top() + maxHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
