class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0;
        if(p.size() <= 1) return 0;
        int cur = p[0];
        for(int i=1;i<p.size();i++) {
            if(p[i] > cur) {
                int prof = p[i]-cur;
                ans = max(ans,prof);
            } else {
                cur = p[i];
            }
        }
        return ans;
    }
};