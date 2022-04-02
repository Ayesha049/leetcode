class Solution {
public:
    bool check(string s,int st,int en)
    {
        while(st<en)
        {
            if(s[st]!=s[en]) return false;
            st++;
            en--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                if(check(s,l+1,r)) return true;
                if(check(s,l,r-1)) return true;
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};