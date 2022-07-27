class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr2.size();i++) {
            mp[arr2[i]] = i;
        }
        vector<pair<int,int> >v;
        int mxCount = arr2.size();
        for(int i=0;i<arr1.size();i++) {
            int pos;
            if(mp.find(arr1[i]) != mp.end()) {
                pos = mp[arr1[i]];
            } else {
                pos = mxCount;
            }
            v.push_back(make_pair(pos,arr1[i]));
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<v.size();i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};