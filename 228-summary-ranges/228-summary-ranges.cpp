class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        int st = nums[0];
        int en = st;
        for(int i=1;i<nums.size();i++) {
            if(nums[i] == en + 1) {
                en++;
            } else {
                string s = to_string(st);
                if(st != en) {
                    s+="->";
                    s+= to_string(en);
                }
                ans.push_back(s);
                st = nums[i];
                en = nums[i];
            }
        }
        string s = to_string(st);
        if(st != en) {
            s+="->";
            s+= to_string(en);
        }
        ans.push_back(s);
        return ans;
    }
};