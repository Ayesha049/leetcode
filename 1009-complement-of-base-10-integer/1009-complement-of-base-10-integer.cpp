class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans = 0;
        vector<bool> v;
        while(n > 0) {
            int bit = n%2;
            n/=2;
            v.push_back(bit == 0 ? 1 : 0);
        }
        for(int i=v.size()-1;i>=0;i--) {
            ans = ans<<1;
            ans |= v[i];
        }
        return ans;
    }
};