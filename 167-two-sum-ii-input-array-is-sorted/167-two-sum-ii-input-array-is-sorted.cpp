class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                vector<int>v;
                v.push_back(mp[target-nums[i]]+1);
                v.push_back(i+1);
                return v;
            }
            mp[nums[i]] = i;
        } 
        vector<int>v;;
        return v;
    }
};