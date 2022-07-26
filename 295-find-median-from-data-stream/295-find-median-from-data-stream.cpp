class MedianFinder {
public:
    priority_queue<int>secondHalf;
    priority_queue<int,vector<int>,greater<int> >firstHalf;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(firstHalf.size() == 0 || firstHalf.top() < num) {
            firstHalf.push(num);
        } else {
            secondHalf.push(num);
        }
        
        if(firstHalf.size() > secondHalf.size() + 1) {
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        } else if (firstHalf.size() + 1 < secondHalf.size()) {
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
    }
    
    double findMedian() {
        if(firstHalf.size() == secondHalf.size()) {
            if(firstHalf.size() == 0) return 0;
            double a = firstHalf.top();
            double b = secondHalf.top();
            return (a+b)/2;
        } else {
            return firstHalf.size() > secondHalf.size() ? firstHalf.top() : secondHalf.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */