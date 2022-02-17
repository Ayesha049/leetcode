class Solution {
public:
    void func(vector<int>& can, int target, int pos, vector<int> &v, set<vector<int> > &ans) {
        if(target == 0) {
            ans.insert(v);
            return;
        }
        if(target < 0 || pos>=can.size()) return;
        v.push_back(can[pos]);
        func(can,target-can[pos], pos,v,ans);
        v.pop_back();
        func(can,target, pos+1,v,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int> > st;
        vector<int> v;
        func(candidates, target, 0, v, st);
        vector<vector<int>> ans;
        for(auto it=st.begin(); it != st.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};