class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,-1);
        for(int i=0;i<=n;i++) {
            solve(i,ans);
        }
        return ans;
    }
    int solve(int n, vector<int>&memo) {
        if(n==0) memo[n] = 0;
        if(n==1) memo[n] = 1;
        if(memo[n] == -1) {
            if(n%2 == 0) {
                memo[n] = solve(n/2, memo);
            } else {
                memo[n] = 1 + solve(n/2, memo);
            }
        }
        return memo[n];
    }
};