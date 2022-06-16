class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        string ans = "";
        int st=0,en=0;
        int len = 1;
        for(int i=0;i<s.length();i++)
        {
            //odd
            int stt = i-1;
            int enn = i+1;
            while(stt>=0 && enn<s.length())
            {
                if(s[stt]==s[enn])
                {
                    int now = enn - stt +1;
                    if(now>len)
                    {
                        len = now;
                        st = stt;
                        en = enn;
                    }
                    stt--;
                    enn++;
                }
                else break;
            }
            
            //even
            stt = i;
            enn = i+1;
            while(stt>=0 && enn<s.length())
            {
                if(s[stt]==s[enn])
                {
                    int now = enn - stt +1;
                    if(now>len)
                    {
                        len = now;
                        st = stt;
                        en = enn;
                    }
                    stt--;
                    enn++;
                }
                else break;
            }
        }
        for(int i=st;i<=en;i++) ans+=s[i];
        return ans;
        
    }
};