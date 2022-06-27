class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n = cards.size();
        int ans = 0;
        int sum = 0;
        for(int i=0;i<k;i++) sum+=cards[i];
        ans = sum;
        for(int i=1;i<=k;i++) {
            sum-=cards[k-i];
            sum+=cards[n-i];
            ans= max(sum,ans);
        }
        return ans;
    }
};