class Solution {
public:
    int countSubstrings(string s) {
        if(s.length()<=1) return s.length();
        int cnt = s.length();
        for(int i=0;i<s.length();i++)
        {
            //odd
            int stt = i-1;
            int enn = i+1;
            while(stt>=0 && enn<s.length())
            {
                if(s[stt]==s[enn])
                {
                    cnt++;
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
                    cnt++;
                    stt--;
                    enn++;
                }
                else break;
            }
        }
        return cnt;
    }
};