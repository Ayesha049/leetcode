class Solution {
public:
    int titleToNumber(string s) {
        long long base = 1;
        long long ans = 0;
        for(int i=s.length()-1; i>=0; i--) {
            int val = (s[i] - 'A') + 1;
            ans += val * base;
            base *= 26;
        }
        return ans;
    }
};