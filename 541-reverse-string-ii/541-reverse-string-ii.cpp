class Solution {
public:
    void rev(string &s, int st, int en,int k) {
        for(int j=0;j<k/2;j++) {
                char temp = s[en-j];
                s[en-j] = s[st+j];
                s[st+j] = temp;
            }
    }
    
    string reverseStr(string s, int k) {
        for(int i=0;i<s.length(); i+=(2*k)) {
            int st = i;
            int en = (i+k) > s.length() ? s.length() : (i+k);
            en--;
            rev(s,st,en,(en-st+1));
            
        }
        return s;
    }
};
