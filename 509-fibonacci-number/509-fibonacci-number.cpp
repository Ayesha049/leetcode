class Solution {
public:
    long long func(int n, vector<long long> &memo) {
        if( n==0 || n==1) return n;
        if(memo[n] == -1) {
            memo[n] = func(n-1,memo) + func(n-2,memo);
        }
        return memo[n];
    }
    int fib(int n) {
        vector<long long>memo(n+1,-1);
        return func(n,memo);
    }
};