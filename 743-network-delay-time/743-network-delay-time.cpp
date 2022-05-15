class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int> > temp;
        vector<vector<pair<int,int> > > adj(n+1,temp);
        for(int i=0;i<times.size();i++) {
            adj[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > >q;
        q.push(make_pair(0,k));
        int ans = 0;
        vector<int>visited(n+1,INT_MAX);
        visited[k] = 0;
        while(!q.empty()) {
            int node = q.top().second;
            int d = q.top().first;
            q.pop();
            for(int i=0;i<adj[node].size();i++) {
                int nd = adj[node][i].first;
                int dist = d+adj[node][i].second;
                // cout<<node<<" "<<nd<<" "<<dist<<endl;
                if(visited[nd] > dist) {
                    visited[nd] = dist;
                    q.push(make_pair(dist,nd));
                }
            }
        }
        for(int i=1;i<=n;i++) {
            if(visited[i] == INT_MAX) return -1;
            ans = max(ans,visited[i]);
        }
        return ans;
    }
};