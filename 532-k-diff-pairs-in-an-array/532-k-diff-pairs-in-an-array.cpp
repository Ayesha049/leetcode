class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        unordered_map<int,int>::iterator it;
        int ans = 0;
        for(it=mp.begin();it!=mp.end();it++) {
            int n = it->first;
            if(k==0) {
                if(it->second>=2) ans++;
            } else {
                if(mp.find(n-k)!=mp.end()) ans++;
            }
        }
        return ans;
    }
};