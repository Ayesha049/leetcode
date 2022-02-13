class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        queue<pair<vector<int>,int> >q;
        
        vector<int>v;
        q.push(make_pair(v,-1));
        
        while(!q.empty())
        {
            vector<int> vv = q.front().first;
            int pos = q.front().second;
            q.pop();
            ans.push_back(vv);
            for(int i=pos+1;i<nums.size();i++)
            {
                if(i<nums.size())
                {
                    vector<int> now = vv;
                    now.push_back(nums[i]);
                    q.push(make_pair(now,i));
                }
            }
        }
        
        return ans;
        
    }
};