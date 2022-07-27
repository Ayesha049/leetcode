class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        auto comp = [&](int a, int b) {
            return mp[a] == mp[b] ? a > b : mp[a] < mp[b];
        };
        sort(nums.begin(),nums.end(),comp);
        return nums;
    }
};