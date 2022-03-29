class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int pos = 0;
        while(pos<nums.size()) {
            int n = nums[pos];
            if(n==pos+1) {
                pos++;
            } else {
                int temp = nums[n-1];
                if(temp == n) return n;
                nums[n-1] = n;
                nums[pos] = temp;
            }
        }
        return 0;
    }
};