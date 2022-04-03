class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = -1;
        int mnpos = nums.size()-1;
        int mn = INT_MAX;
        for(int i=nums.size()-1;i>=1;i--)
        {
            if(nums[i]>nums[i-1])
            {
                pos = i-1;
                break;
            }
        }
        if(pos==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=pos+1;i<nums.size();i++)
        {
            if(nums[i]>nums[pos] && mn>=nums[i])
            {
                mnpos = i;
                mn = nums[i];
            }
        }
        
        int temp = nums[pos];
        nums[pos] = nums[mnpos];
        nums[mnpos] = temp;
        reverse(nums.begin()+pos+1,nums.end());
    }
};