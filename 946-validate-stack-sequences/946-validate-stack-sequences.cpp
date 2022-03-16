class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()) return false;
        stack<int>st;
        int l = 0;
        int r = 0;
        while(l<pushed.size()) {
            // cout<<pushed[l]<<endl;
            if(pushed[l] == popped[r] || (!st.empty() && popped[r] == st.top())) {
                if(pushed[l] == popped[r] ) {
                    r++;
                    l++;
                }
                if(!st.empty() && popped[r] == st.top()) {
                while((!st.empty() && popped[r] == st.top())) {
                        st.pop();
                        r++;
                    }
                }
            } else {
                st.push(pushed[l]);
                l++;
            }
        }
        
        while(r<popped.size()) {
            // cout<<st.top()<<" "<<popped[r]<<" -- ";
            if(st.empty()) return false;
            if(st.top() != popped[r]) return false;
            st.pop();
            r++;
        }
        
        return st.empty();
    }
};