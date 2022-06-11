class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = INT_MAX;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            sum+=nums[i];
        }
        int l = 0, r = 0;
        int cur = 0;
        int tar = sum - x;
        if(tar<0) return -1;
        if(tar==0) return n;
        while(r<n) {
            cur+=nums[r++];
            while(cur>tar) {
                cur-=nums[l++];
            }
            if(cur == tar) {
                int cnt = r-l;
                ans = min(ans,n-cnt);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};