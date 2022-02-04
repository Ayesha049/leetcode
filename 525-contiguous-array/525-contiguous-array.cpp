class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int mxLength = 0;
        int sum = 0;
        map<int,int> posMap;
        for(int i=0;i<nums.size(); i++) {
            sum += nums[i];
            if(nums[i] == 0) sum--;
            if(sum == 0) {
                mxLength = max(mxLength, i+1);
            } else if (posMap.find(sum) != posMap.end()) {
                int len = i - posMap[sum];
                    mxLength = max(mxLength, len);
            } else {
                posMap[sum] = i;
            }
        }
        
        return mxLength;
    }
};