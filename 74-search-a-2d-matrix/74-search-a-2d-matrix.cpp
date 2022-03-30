class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        if(n==0) return false;
        int m = mat[0].size();
        if(m==0) return false;
        int lo = 0;
        int hi = n*m - 1;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            int i = mid/m;
            int j = mid%m;
            if(mat[i][j] == target) return true;
            if(mat[i][j] < target) {
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return false;
    }
};