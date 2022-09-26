class MyCircularQueue {
public:
    vector<int>v;
    int size;
    int st;
    int en;
    MyCircularQueue(int k) {
        size = 0;
        st=0;
        en=0;
        for(int i=0;i<k;i++) {
            v.push_back(-1);
        }
    }
    
    bool enQueue(int value) {
        if(!isFull()) {
            en = en%(v.size());
            v[en++] = value;
            size++;
            return true;
        } 
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()) {
            st = st%(v.size());
            v[st++] = -1;
            size--;
            return true;
        } 
        return false;
    }
    
    int Front() {
        st = st%(v.size());
        return v[st];
    }
    
    int Rear() {
        int pos = (en-1)%(v.size());
        return v[pos];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==v.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */