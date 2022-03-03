class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt = 0;
        if(nums.size() < 3) return cnt;
        int st = 0;
        int en = 1;
        int diff = nums[en] - nums[st];
        for(int i=2; i<nums.size();i++) {
            if(nums[i] - nums[en] == diff) {
                en++;
            } else {
                int n = (en - st + 1) - 2;
                // cout<<"st :"<<st<<" en "<<en<<" "<<n<<endl;
                if(n > 0) {
                    cnt += ((n*(n+1))/2);
                }
                st = en;
                en++;
                diff = nums[en] - nums[st];
            }
        }
        int n = (en - st + 1) - 2;
        if(n > 0) {
            cnt += ((n*(n+1))/2);
        }
        // cout<<"st :"<<st<<"en "<<en<<" "<<n<<endl;
        return cnt;
    }
};