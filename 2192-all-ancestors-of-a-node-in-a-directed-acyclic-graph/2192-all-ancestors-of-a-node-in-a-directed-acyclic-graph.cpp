class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& pre) {
        vector<int> temp;
        vector<vector<int> > adj(n,temp);
        unordered_map<int,int>indegree;
        for(int i=0;i<pre.size();i++) {
            adj[pre[i][0]].push_back(pre[i][1]);
            indegree[pre[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        set<int>st;
        vector<set<int>>v(n,st);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            set<int> s = v[node];
            s.insert(node);
            for(int i=0;i<adj[node].size();i++) {
                indegree[adj[node][i]]--;
                v[adj[node][i]].insert(s.begin(),s.end());
                if(indegree[adj[node][i]] == 0) {
                    q.push(adj[node][i]);
                }
            }
        }
        vector<vector<int> >ans;
        for(int i=0;i<n;i++) {
            vector<int> t(v[i].begin(),v[i].end());
            ans.push_back(t);
        }
        return ans;
    }
};