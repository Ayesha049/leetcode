class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int l=0,r=p.size()-1;
        int cnt = 0;
        while(l<=r) {
            if(p[l] + p[r] <= limit) {
                l++;
            } 
            r--;
            cnt++;
        }
        return cnt;
    }
};