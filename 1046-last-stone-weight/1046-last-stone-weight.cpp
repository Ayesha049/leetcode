class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int>pq;
        for(int i=0;i<v.size();i++) {
            pq.push(v[i]);
        }
        while(pq.size() > 1) {
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            if(t1>t2) {
                pq.push(t1-t2);
            }
        }
        if(pq.size() == 0) return 0;
        return pq.top();
    }
};