class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n==0) return mat;
        int m = mat[0].size();
        if(m==0) return mat;
        vector<vector<int> >dist(n, vector<int> (m, INT_MAX - 10000));
        //top and left
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int topx = i-1;
                    int topy = j;
                    if(topx>=0 && dist[i][j] > dist[topx][topy] + 1) {
                        dist[i][j] = dist[topx][topy] + 1;
                    }
                    int leftx = i;
                    int lefty = j-1;
                    if(lefty>=0 && dist[i][j] > dist[leftx][lefty] + 1) {
                        dist[i][j] = dist[leftx][lefty] + 1;
                    }
                }
            }
        }
        
        //bottom and right
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    int bottomx = i+1;
                    int bottomy = j;
                    if(bottomx<n && dist[i][j] > dist[bottomx][bottomy] + 1) {
                        dist[i][j] = dist[bottomx][bottomy] + 1;
                    }
                    int rightx = i;
                    int righty = j+1;
                    if(righty<m && dist[i][j] > dist[rightx][righty] + 1) {
                        dist[i][j] = dist[rightx][righty] + 1;
                    }
                }
            }
        }
        return dist;
    }
};