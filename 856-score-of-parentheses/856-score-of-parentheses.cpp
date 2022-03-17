class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int>v;
        int ans = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '(') {
                v.push_back(0);
            } else {
                int x = v.back();
                v.pop_back();
                if(x==0) {
                    x=1;
                } else {
                    x*=2;
                }
                if(v.size() == 0) {
                    ans+=x;
                } else {
                    v[v.size() - 1] += x;
                }
            }
        }
        return ans;
    }
};