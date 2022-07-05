class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 0) return 0;
        int ans = 1;
        int count = 1;
        int i = 1;
        int prev = 0;
        while(i<nums.size()) {
            if(nums[i] == nums[prev]) {
                i++;
            } else if(nums[i] == nums[prev] + 1) {
                count++;
                prev = i;
                i++;
            } else {
                count = 1;
                prev = i;
                i++;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};