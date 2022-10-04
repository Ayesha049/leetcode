class Solution {
public:
    int minCost(string c, vector<int>& v) {
        int total=v[0],mx=v[0],ans=0;
        for(int i=1;i<c.length();i++) {
            if(c[i] == c[i-1]) {
                total+=v[i];
                mx = max(mx,v[i]);
            } else {
                ans+=total-mx;
                total = v[i];
                mx = v[i];
            }
        }
        ans += total-mx;
        return ans;
    }
};