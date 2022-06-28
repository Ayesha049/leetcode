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
        stack<int>st;
        for(int i=0;i<=mx;i++) {
            st.push(i);
        }
        int cnt = 0;
        for(int i=v.size()-1;i>=0;i--) {
            while(!st.empty() && st.top() > v[i]) {
                st.pop();
            }
            if(st.empty()) {
                cnt+=v[i];
            } else {
                cnt+= v[i] - st.top();
                st.pop();
            }
        }
        return cnt;
    }
};