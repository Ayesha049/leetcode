class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> ans;
        if(in.size() == 0) return ans;
        sort(in.begin(),in.end());
        ans.push_back(in[0]);
        for(int i=1;i<in.size();i++) {
            if(in[i][0] > ans.back()[1]) {
                ans.push_back(in[i]);
            } else {
                vector<int>v = ans.back();
                ans.pop_back();
                v[0] = min(v[0], in[i][0]);
                v[1] = max(v[1], in[i][1]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};