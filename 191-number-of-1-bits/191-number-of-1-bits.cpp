class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        int mask = 1;
        while(n!=0) {
            cnt += n&mask;
            n = n>>1;
        }
        return cnt;
    }
};