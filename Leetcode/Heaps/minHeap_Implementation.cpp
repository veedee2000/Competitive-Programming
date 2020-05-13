class minHeap{
    
    vector<int>heap;

public:
    
    minHeap(){
        heap.push_back(0);
    }
    
    void push(int val){
        heap.push_back(val);
        int n = heap.size() - 1;
        
        while(n > 1){
            if(heap[n] < heap[n / 2]) swap(heap[n],heap[n / 2]);
            else break;
            n /= 2;
        }
    }
    
    int top(){
        return heap[1];
    }
    
    void pop(){
        int n = heap.size() - 1;
        swap(heap[1],heap[n]);
        heap.pop_back();
        
        int i = 1;
        while(i < heap.size()){
            if(2 * i + 1 < heap.size()){
                int minIndex;
                if(heap[2 * i] < heap[2 * i + 1]) minIndex = 2 * i;
                else minIndex = 2 * i + 1;
                
                if(heap[i] > heap[minIndex]) { swap(heap[i],heap[minIndex]); i = minIndex; }
                else break;
            }
            else if(2 * i < heap.size()){
                if(heap[i] > heap[2 * i]) { swap(heap[i],heap[2 * i]); i = 2 * i; }
                else break;
            }
            else break;
        }
    }
    
    int getSize(){
        return heap.size() - 1;
    }
};

