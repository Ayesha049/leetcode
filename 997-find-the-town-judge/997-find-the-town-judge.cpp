class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n+1,0);
        map<int,set<int> >mp;
        for(int i=0;i<trust.size();i++) {
            int a = trust[i][0];
            int b = trust[i][1];
            mp[b].insert(a);
            v[a]++; 
        }
        int ans = -1;
        for(int i=1;i<=n;i++) {
            if(v[i] == 0 && mp[i].size() == n-1) {
                if(ans == -1) {
                    ans = i;
                } else {
                    return -1;
                }
            }
        }
        return ans;
    }
};