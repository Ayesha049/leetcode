class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& ws, string p) {
        unordered_map<char,char>f,s;
        vector<string>ans;
        for(int j=0;j<ws.size();j++) {
            string w = ws[j];
            f.clear();
            s.clear();
            if(w.length()!=p.length()) continue;
            int flag = 0;
            for(int i = 0; i < w.length(); i++) {
                if(f.find(w[i]) == f.end() && s.find(p[i])==s.end()) {
                    f[w[i]] = p[i];
                    s[p[i]] = w[i];
                } else if(f.find(w[i]) == f.end() || s.find(p[i])==s.end()) {
                    flag = 1;
                    break;
                } else {
                    if(f[w[i]] == p[i] && s[p[i]] == w[i]) continue;
                    else {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag==0) ans.push_back(w);
        }
        return ans;
    }
};