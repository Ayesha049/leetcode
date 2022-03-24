class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        map<int,int>endPos;
        for(int i = 0; i < s.length(); i++) {
            endPos[s[i]] = i;
        }
        
        int st = 0;
        int l = endPos[s[st]];
        int i=0;
        while(i<s.length()) {
            // cout<<s[i]<<" "<<endPos[s[i]]<<endl;
            while(i<=l) {
                int curEnd =  endPos[s[i]];
                i++;
                l = max(l,curEnd);
            }
            ans.push_back((l-st) + 1);
            st=i;
            l = endPos[s[i]];
            
        }
        return ans;
    }
};