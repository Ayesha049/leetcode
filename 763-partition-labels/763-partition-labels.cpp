class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>ans;
        if(S.length() == 0) return ans;
        unordered_map<char,int>fst,lst;
        for(int i=0;i<S.length();i++) {
            if(fst.find(S[i])==fst.end()) {
                fst[S[i]] = i;
                lst[S[i]] = i;
            } else lst[S[i]] = i;
        }
        int f = fst[S[0]];
        int l = lst[S[0]];
        for(int i = 1; i < S.length(); i++) {
            if(fst[S[i]] > l) {
                ans.push_back(l-f+1);
                f = fst[S[i]];
                l = lst[S[i]];
            } else {
                l = max(lst[S[i]],l);
            }
        }
        ans.push_back(l-f+1);
        return ans;
    }
};