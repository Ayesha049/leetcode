class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        int n = mat.size();
        if(n==0) return ans;
        int m = mat[0].size();
        if(m==0) return ans;
        for(int i=0;i<m;i++) {
            vector<int>v;
            for(int j=0;j<n;j++) {
                v.push_back(mat[j][i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};