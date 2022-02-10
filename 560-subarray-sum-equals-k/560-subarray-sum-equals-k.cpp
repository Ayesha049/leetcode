class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int cnt = 0;
        int sum = 0;
        unordered_map<int,int>seen;
        seen[0] = 1;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
            cnt+=seen[sum-k];
            seen[sum]++;
        }
        return cnt;
    }
};