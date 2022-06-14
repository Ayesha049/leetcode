class Solution {
public:
    int func(string w1, int pos1, string w2, int pos2, vector<vector<int> >&dp) {
        if(pos1 < 0) return pos2+1;
        if(pos2 < 0) return pos1+1;
        if(dp[pos1][pos2] == -1) {
            if(w1[pos1] == w2[pos2]) {
                dp[pos1][pos2] = func(w1,pos1-1,w2,pos2-1,dp);
            }else {
                dp[pos1][pos2] = 1 + min(func(w1,pos1,w2,pos2-1,dp),func(w1,pos1-1,w2,pos2,dp));
            }
        }
        return dp[pos1][pos2];
    }
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<int>temp(m,-1);
        vector<vector<int> >dp(n,temp);
        return func(w1,n-1,w2,m-1,dp);
    }
};