class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        if(m==0) return 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>> >, greater<pair<int,pair<int,int> > > > pq;
        map<pair<int,int>,int>dist;
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        dist[make_pair(0,0)] = 1;
        pq.push(make_pair(1,make_pair(0,0)));
        int dx[] = {0,0,1,-1,-1,-1,1,1};
        int dy[] = {1,-1,0,0,-1,1,-1,1};
        while(!pq.empty()) {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int dd=0;dd<8;dd++) {
                int i = x+dx[dd];
                int j = y+dy[dd];
                if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 0) {
                    if(dist.find(make_pair(i,j)) == dist.end() || d+1 < dist[make_pair(i,j)]) {
                        dist[make_pair(i,j)] = d+1;
                        pq.push(make_pair(d+1,make_pair(i,j)));
                    } 
                }
            }
        }
        if(dist.find(make_pair(n-1,m-1)) == dist.end()) return -1;
        return dist[make_pair(n-1,m-1)];
    };
};