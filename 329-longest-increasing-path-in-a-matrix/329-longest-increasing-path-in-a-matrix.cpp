class Solution {
public:
    int dfs(int x,int y,int n,int m, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(x>=n || x<0 || y>=m || y<0) return 0;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        if(dp[x][y] == -1) {
            int mx = 1;
            for(int d=0;d<4;d++) {
                int posx = x+dx[d];
                int posy = y+dy[d];
                if(posx>=0 && posx<n && posy>=0 && posy<m && mat[posx][posy] > mat[x][y]) {
                    mx = max(mx, 1+dfs(posx,posy,n,m,mat,dp));
                }
            }
            dp[x][y] = mx;
        }
        return dp[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        if( n==0 ) return 0;
        int m = mat[0].size();
        if(m == 0) return 0;
        vector<int>temp(m,-1);
        vector<vector<int> > dp(n,temp);
        
        int mx = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(dp[i][j] == -1) {
                    dfs(i,j,n,m,mat,dp);
                }
                mx = max(mx,dp[i][j]);
            }
        }
        
        return mx;
    }
};