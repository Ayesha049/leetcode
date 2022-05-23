class Solution {
public:
    int func(vector<vector<int> > &v, int pos, int z,int o, vector<vector<vector<int> > >&dp) {
        if(pos < 0) return 0;
        // if(z<0 || o<0) return 0;
        if(dp[pos][z][o] == -1) {
            if(v[pos][0] > z || v[pos][1] > o) {
                dp[pos][z][o] = func(v,pos-1,z,o,dp);
            } else {
                dp[pos][z][o] = max(func(v,pos-1,z,o,dp), 1 + func(v,pos-1,z-v[pos][0],o-v[pos][1],dp));
            }
            
        }
        return dp[pos][z][o];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > v;
        for(int i=0;i<strs.size();i++) {
            int z=0,o=0;
            for(int j=0;j<strs[i].size();j++) {
                if(strs[i][j] == '0') z++;
                else o++;
            }
            vector<int>temp;
            temp.push_back(z);
            temp.push_back(o);
            v.push_back(temp);
        }
        int sz = v.size();
        vector<int> t(n+1,-1);
        vector<vector<int> > tt(m+1,t);
        vector<vector<vector<int> > >dp(sz,tt); // pos,m,n
        return func(v,sz-1,m,n,dp);
    }
};