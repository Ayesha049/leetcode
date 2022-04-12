class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if(n==0) return;
        int m = board[0].size();
        if(m==0) return;
        vector<bool>temp(m,0);
        vector<vector<bool> >v(n,temp);
        int dx[] = {0,0,1,-1,-1,-1,1,1};
        int dy[] = {1,-1,0,0,-1,1,-1,1};
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int cnt = 0;
                for(int d=0;d<8;d++) {
                    int x = i+dx[d];
                    int y = j+dy[d];
                    if(x>=0 && x<n && y>=0 && y<m) {
                        cnt+=board[x][y];
                    }
                }
                int val = 0;
                if(board[i][j] == 1) {
                    if(cnt == 2 || cnt == 3) {
                        val = 1;
                    }
                } else {
                    if(cnt == 3) val = 1;
                }
                v[i][j] = val;
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                board[i][j] = v[i][j];
            }
        }
    }
};