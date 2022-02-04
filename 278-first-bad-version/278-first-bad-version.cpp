// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long lo = 1;
        long long hi = n;
        int ans = 0;
        while(lo<=hi) {
            long long mid = (lo+hi)/2;
            if(isBadVersion(mid)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
};