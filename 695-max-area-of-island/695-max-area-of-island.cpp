class Solution {
public:
    int floodFill(vector<vector<int>>& image, int sr, int sc,int n,int m, vector<vector<int>> &visited) {
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        queue<pair<int,int> > q;
        q.push(make_pair(sr,sc));
        int cnt = 0;
        visited[sr][sc] = 1;
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            cnt++;
            for(int i=0;i<4;i++) {
                int dr = r + dx[i];
                int dc = c + dy[i];
                if(dr>=0 && dr<n && dc>=0 && dc<m) {
                    if(image[dr][dc] == 1 && visited[dr][dc] == 0) {
                        q.push(make_pair(dr,dc));
                        visited[dr][dc] = 1;
                    }
                }
            }
        }
        return cnt;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        if(m == 0) return 0;
        vector<int>v(m,0);
        vector<vector<int>> visited(n,v);
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1 && visited[i][j] == 0) {
                    ans = max(ans, floodFill(grid,i,j,n,m,visited));
                }
            }
        }
        return ans;
    }
};