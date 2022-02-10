class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        if(n == 0) return image;
        int m = image[0].size();
        if(m == 0) return image;
        vector<int>v(m,0);
        vector<vector<int>> visited(n,v);
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        queue<pair<int,int> > q;
        q.push(make_pair(sr,sc));
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            int val = image[r][c];
            image[r][c] = newColor;
            q.pop();
            for(int i=0;i<4;i++) {
                int dr = r + dx[i];
                int dc = c + dy[i];
                if(dr>=0 && dr<n && dc>=0 && dc<m) {
                    if(image[dr][dc] == val && visited[dr][dc] == 0) {
                    q.push(make_pair(dr,dc));
                        visited[dr][dc] = 1;
                }
                }
            }
        }
        return image;
    }
};