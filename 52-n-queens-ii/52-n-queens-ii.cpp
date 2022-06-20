class Solution {
public:
    void func(int pos,int &n,vector<string>&board,int &cnt,vector<vector<int> >&v) {
        if(pos==n) {
            cnt++;
            return;
        }
        for(int i=0;i<n;i++) {
            if(v[pos][i] == 0) {
                board[pos][i] = 'Q';
                int k = i+1, j = pos+1;
                while(j<n && k<n) {
                    v[j][k]++;
                    j++;
                    k++;
                }
                j=pos+1;
                k = i-1;
                while(j<n && k>=0) {
                    v[j][k]++;
                    j++;
                    k--;
                }
                j = pos+1;
                while(j<n) {
                    v[j][i]++;
                    j++;
                }
                func(pos+1,n,board,cnt,v);
                board[pos][i] = '.';
                k = i+1, j = pos+1;
                while(j<n && k<n) {
                    v[j][k]--;
                    j++;
                    k++;
                }
                j=pos+1;
                k = i-1;
                while(j<n && k>=0) {
                    v[j][k]--;
                    j++;
                    k--;
                }
                j = pos+1;
                while(j<n) {
                    v[j][i]--;
                    j++;
                }
            }
        }
    }
    
    int totalNQueens(int n) {
        string s = "";
        for(int i=0;i<n;i++) s+='.';
        vector<string>temp(n,s);
        vector<int>t(n,0);
        vector<vector<int> >v(n,t);
        int ans = 0;
        func(0,n,temp,ans,v);
        return ans;
    }
};