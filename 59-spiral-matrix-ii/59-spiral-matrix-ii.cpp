class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int>temp(n,0);
        vector<vector<int> >v(n,temp);
        int val = 1;
        int x=0,y=0;
        v[x][y] = val++;
        while(val<=(n*n)) {
            //go right
            while(y+1 < n && v[x][y+1] == 0) {
                y++;
                v[x][y] = val++;
            }
            //go down
            while(x+1 < n && v[x+1][y] == 0) {
                x++;
                v[x][y] = val++;
            }
            //go left
            while(y-1 >= 0 && v[x][y-1] == 0) {
                y--;
                v[x][y] = val++;
            }
            //go up
            while(x-1 >= 0 && v[x-1][y] == 0) {
                x--;
                v[x][y] = val++;
            }
        }
        return v;
    }
};