class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        int n = A.size();
        if(n==0) return 0;
        vector<int>temp(2,1);
        vector<vector<int> >dp(n,temp);
        int inc = 1;
        int dec = 0;
        int ans = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(A[j] > A[i]) {
                    dp[i][dec] = max(dp[i][dec],dp[j][inc]+1);
                } else if(A[j] < A[i]){
                    dp[i][inc] = max(dp[i][inc],dp[j][dec]+1);
                }
            }
            ans = max(ans,max(dp[i][inc],dp[i][dec]));
        }
        return ans;
    }
};