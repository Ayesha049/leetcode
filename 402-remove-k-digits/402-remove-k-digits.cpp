class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = "";
        for(int i=0;i<num.length();i++) {
            int l = s.length() - 1;
            while(l >= 0 && k > 0 && s[l] > num[i]) {
                s.pop_back();
                k--;
                l--;
            }
            s+=num[i];
        }
        while(k>0) {
            if(s.length() == 0) return "0";
            s.pop_back();
            k--;
        }
        if(s.length() == 0) return "0";
        int zeroPos = 0;
        while(zeroPos < s.length()-1 && s[zeroPos] == '0') {
            zeroPos++;
        }
        
        return s.substr(zeroPos);
    }
};