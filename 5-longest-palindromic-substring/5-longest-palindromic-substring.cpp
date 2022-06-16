class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0) return s;
        int mxlen = 1;
        int st = 0;
        int en = 0;
        int n = s.length();
        vector<bool>temp(n,false);
        vector<vector<bool> >dp(n,temp);
        for(int len=2;len<=n;len++) {
            for(int i=0; i+len-1<n; i++) {
                dp[i][i+len-1] = (s[i] == s[i+len-1] && (len<=3 || dp[i+1][i+len-2]));
                if(dp[i][i+len-1] && len>mxlen) {
                    mxlen = len;
                    st = i;
                    en = i+len-1; 
                }
            }
        }
        string ans = "";
        for(int i=st;i<=en;i++) {
            ans+=s[i];
        }
        return ans;
    }
};