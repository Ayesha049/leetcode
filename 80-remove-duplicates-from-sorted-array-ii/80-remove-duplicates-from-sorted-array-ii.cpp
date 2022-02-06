class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int l = 2, r = 2;
        while(r<nums.size()) {
            if(!(nums[r] == nums[l-1] && nums[r] == nums[l-2])) {
                nums[l++] = nums[r];
            }
            r++;
        }
        return l;
    }
};