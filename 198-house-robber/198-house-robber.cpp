class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int>memo(n, 0);
        memo[0] = nums[0];
        memo[1] = max(memo[0], nums[1]);
        for(int i=2;i<n;i++) {
            memo[i] = max(memo[i-1], nums[i] + memo[i-2]);
        }
        return memo[n-1];
    }
};