class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(st.empty()) {
                    return false;
                }
                char ch = st.top();
                if(s[i] == ')') {
                    if(ch != '(') {
                        return false;
                    }
                } else if(s[i] == '}') {
                    if(ch != '{') {
                        return false;
                    }
                } else {
                    if(ch != '[') {
                        return false;
                    }
                }
                st.pop();
            }
        }
        return st.size() == 0;
    }
};