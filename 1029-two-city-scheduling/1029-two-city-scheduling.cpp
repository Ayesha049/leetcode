class Solution {
public:
    int func(vector<vector<int> >&dp, vector<vector<int>>& cost, int &n, int sza,int szb,int pos)
    {
        if(pos==cost.size()) return 0;
        if(sza==0)
        {
            int cst = 0;
            for(int i=pos;i<cost.size();i++)
            {
                cst+=cost[i][1];
            }
            //cout<<"costB "<<cst<<endl;
            return cst;
        }
        if(szb==0)
        {
            int cst = 0;
            for(int i=pos;i<cost.size();i++)
            {
                cst+=cost[i][0];
            }
            //cout<<"costA "<<cst<<endl;
            return cst;
        }
        if(dp[sza][szb]==-1)
        {
            dp[sza][szb] = min(cost[pos][0]+func(dp,cost,n,sza-1,szb,pos+1),
                              cost[pos][1]+func(dp,cost,n,sza,szb-1,pos+1));
        }
        //cout<<sza<<" , "<<szb<<" : "<<dp[sza][szb]<<endl;
        return dp[sza][szb];
    }
    
    
    int twoCitySchedCost(vector<vector<int>>& cost) {
        int n = cost.size();
        n/=2;
        vector<int>temp(n+1,-1);
        vector<vector<int> >dp(n+1,temp);
        return func(dp,cost,n,n,n,0);
    }
};