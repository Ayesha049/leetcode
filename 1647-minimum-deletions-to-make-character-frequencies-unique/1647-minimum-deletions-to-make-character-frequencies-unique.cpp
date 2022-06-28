class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        vector<int>v;
        unordered_map<char,int>:: iterator it;
        for(it=mp.begin();it!=mp.end();it++) {
            v.push_back(it->second);
        }
        sort(v.begin(),v.end());
        int mx = v.back();
        int mxFeqAllowed = mx;
        int cnt = 0;
        for(int i=v.size()-1;i>=0;i--) {
            while(mxFeqAllowed != 0 && mxFeqAllowed > v[i]) {
                mxFeqAllowed--;
            }
            if(mxFeqAllowed == 0) {
                cnt+=v[i];
            } else {
                cnt+= v[i] - mxFeqAllowed;
                mxFeqAllowed--;
            }
        }
        return cnt;
    }
};