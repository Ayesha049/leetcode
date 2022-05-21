class Solution {
public:
    long long func(vector<int>& coins,int pos,int amount,int n,vector<vector<long long> >&dp)
    {
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(pos>=n) return INT_MAX;
        if(dp[amount][pos]==-1)
        {
            dp[amount][pos] = min(1+func(coins,pos,amount-coins[pos],n,dp),func(coins,pos+1,amount,n,dp));
        }
        return dp[amount][pos];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<long long>temp(n,-1);
        vector<vector<long long> >dp(amount+1,temp);
        long long ans = func(coins,0,amount,n,dp);
        if(ans>=INT_MAX) return -1;
        return ans;
        
    }
};