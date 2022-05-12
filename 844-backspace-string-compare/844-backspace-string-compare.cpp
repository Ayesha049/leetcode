class Solution {
public:
    string retrive(string s) {
        string s1 = "";
        for(int i=0;i<s.length();i++) {
            if(s[i] != '#') {
                s1+=s[i];
            } else if(s1.length() > 0) {
                s1.pop_back();
            }
        }
        return s1;
    }
    
    bool backspaceCompare(string s, string t) {
        string s1 = retrive(s);
        string s2 = retrive(t);
        return s1==s2;
    }
};