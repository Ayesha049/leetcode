class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<=r) {
            if(nums[l]%2==0) l++;
            else {
                int temp = nums[r];
                nums[r] = nums[l];
                nums[l] = temp;
                r--;
            }
        }
        return nums;
    }
};