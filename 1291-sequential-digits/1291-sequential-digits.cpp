class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        vector<int>ans;
        for(int i=1;i<=9;i++) {
            q.push(i);
        }
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            if(n>=low && n<=high) {
                ans.push_back(n);
            }
            int d = n%10;
            d++;
            if(d<=9) {
                int newN = n*10 + d;
                if(newN <= high) {
                    q.push(newN);
                }
            }
        }
        return ans;
    }
};