class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int>&v, int k,int cur,int rest) {
        if(v.size() == k) {
            if(rest == 0) {
                ans.push_back(v);
            }
            return;
        }
        for(int i=cur;i<=9;i++) {
            if(rest-i >= 0) {
                v.push_back(i);
                func(ans,v,k,i+1,rest-i);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>v;
        func(ans,v,k,1,n);
        return ans;
    }
};