class Solution {
public:
    int dp(int pos, int n, vector<pair<int,int> >&v, vector<int>&memo) {
        if(pos>=n) return 0;
        if(pos == n-1) return v[n-1].first*v[n-1].second;
        if(memo[pos] == -1) {
            if(v[pos+1].first - v[pos].first > 1) {
                memo[pos] = (v[pos].first*v[pos].second) + dp(pos+1,n,v,memo);
            } else {
                int take = (v[pos].first*v[pos].second) + dp(pos+2,n,v,memo);
                int notTake = dp(pos+1,n,v,memo);
                memo[pos] = max(take,notTake);
            }
        }
        return memo[pos];
    }
    
    int deleteAndEarn(vector<int>& nums) {
        vector<pair<int,int> >v;
        map<int,int>cnt;
        for(int i=0;i<nums.size();i++) {
            cnt[nums[i]]++;
        }
        for(auto it=cnt.begin();it!=cnt.end();it++) {
            v.push_back(make_pair(it->first,it->second));
        }
        int n = v.size();
        vector<int>memo(n,-1);
        return dp(0,n,v,memo);
    }
};