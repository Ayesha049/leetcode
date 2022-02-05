class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size() == 0) return nums;
        vector<int>ans;
        int l = 0;
        int r = 0;
        while(r<nums.size()) {
            if(nums[r] >= 0) break;
            r++;
        }
        l = r-1;
        while(ans.size() < nums.size()) {
            if(l<0 && r>=nums.size()) break;
            if(l<0) {
                ans.push_back(nums[r]*nums[r]);
                r++;
            } else if(r>=nums.size()) {
                ans.push_back(nums[l]*nums[l]);
                l--;
            } else {
                if(abs(nums[l])<=abs(nums[r])) {
                    ans.push_back(nums[l]*nums[l]);
                    l--;
                } else {
                    ans.push_back(nums[r]*nums[r]);
                    r++;
                }
            }
        }
        return ans;
    }
};