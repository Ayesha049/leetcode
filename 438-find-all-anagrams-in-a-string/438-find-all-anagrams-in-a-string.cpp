class Solution {
public:
    bool check(vector<int> &v1, vector<int> &v2) {
        if(v1.size() != v2.size()) return false;
        for(int i=0;i<v1.size();i++) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp(26,0);
        vector<int> pMap(26,0);
        for(int i=0;i<p.length();i++) {
            pMap[p[i]-'a']++;
        }
        vector<int> ans;
        int st = 0;
        int l = 0;
        while(l<s.length()) {
            mp[s[l]-'a']++;
            l++;
            if(l>=p.length()) {
                if(check(mp,pMap)){
                    ans.push_back(st);
                }
                mp[s[st]-'a']--;
                st++;
            }
        }
        return ans;
        
    }
};