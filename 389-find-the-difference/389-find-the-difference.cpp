class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>v1(26,0);
        for(int i=0;i<s.length();i++) {
            v1[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++) {
            if(v1[t[i]-'a']==0) return t[i];
            v1[t[i]-'a']--;
        }
        return 'a';
    }
};