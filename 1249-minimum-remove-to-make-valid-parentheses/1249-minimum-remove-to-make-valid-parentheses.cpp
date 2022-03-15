class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_map<int,bool>rmv;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                if(st.empty()) {
                    rmv[i] = true;
                } else st.pop();
            }
        }
        while(!st.empty()) {
            rmv[st.top()] = true;
            st.pop();
        }
        string ans = "";
        for(int i=0;i<s.length();i++) {
            if(rmv.find(i) == rmv.end()) {
                ans += s[i];
            }
        }
        return ans;
    }
};