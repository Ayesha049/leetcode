class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        map<char,bool>mp;
        int mx = 0;
        for(int r=0;r<s.length();r++)
        {
            if(mp[s[r]]==false) mp[s[r]] = true;
            else
            {
                int len = r-l;
                mx = max(mx,len);
                while(mp[s[r]]==true)
                {
                    mp[s[l]] = false;
                    l++;
                }
                mp[s[r]] = true;
            }
        }
        int len = s.length()-l;
        mx = max(mx,len);
        return mx;
    }
};