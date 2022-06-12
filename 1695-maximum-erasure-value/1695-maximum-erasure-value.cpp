class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,bool>mp;
        int sum = 0;
        int mxSum = 0;
        int l=0,r=0;
        while(r<nums.size()) {
            sum+=nums[r];
            while(mp.find(nums[r]) != mp.end()) {
                sum-=nums[l];
                mp.erase(nums[l++]);
            }
            mxSum = max(sum,mxSum);
            mp[nums[r]] = 1;
            r++;
        }
        return mxSum;
    }
};