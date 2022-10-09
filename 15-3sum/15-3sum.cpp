class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int> >st;
        if(nums.size() < 3) return ans;
        int i = 0;
        while(i<nums.size() - 2) {
            int l = i+1;
            int r = nums.size() - 1;
            while(l<r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    ans.push_back(v);
                    int left = nums[l];
                    int right = nums[r]; 
                    while(l < r && nums[l] == left) l++;
                    while(l < r && nums[r] == right) r--;
                } else if(sum < 0) {
                    int left = nums[l];
                    while(l < r && nums[l] == left) l++;
                } else {
                    int right = nums[r]; 
                    while(l < r && nums[r] == right) r--;
                }
            }
            int st = nums[i];
            while(i<nums.size() - 2 && nums[i] == st) i++;
        }
        return ans;
    }
};