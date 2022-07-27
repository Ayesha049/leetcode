class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr2.size();i++) {
            mp[arr2[i]] = i+1;
        }
        auto comp = [&](int a , int b) {
            if(mp[a] == 0  && mp[b]==0) return a<b;
            if(mp[a] == 0)  return false;
            if(mp[b] == 0)   return true;
            return mp[a] < mp[b];
        };
        sort(arr1.begin(),arr1.end(),comp);
        return arr1;
    }
};