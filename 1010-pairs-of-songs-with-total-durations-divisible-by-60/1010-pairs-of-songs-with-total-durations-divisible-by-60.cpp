class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int>mp;
        int ans = 0;
        for(int i=0;i<time.size();i++) {
            int num = time[i]%60;
            int fnd = (60-num)%60;
            ans += mp[fnd];
            mp[num]++;
        }
        return ans;
    }
};