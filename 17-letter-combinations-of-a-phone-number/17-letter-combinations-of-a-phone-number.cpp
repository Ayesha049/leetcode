class Solution {
public:
    void backtrack(int pos,string &d,string &s,vector<string>&ans,map<char,string>&mp) {
        if(pos==d.size()) {
            ans.push_back(s);
            return;
        }
        for(int i=0;i<mp[d[pos]].size();i++) {
            s+=mp[d[pos]][i];
            backtrack(pos+1,d,s,ans,mp);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string>ans;
        if(digits.size()==0) return ans;
        string s="";
        backtrack(0,digits,s,ans,mp);
        return ans;
    }
};