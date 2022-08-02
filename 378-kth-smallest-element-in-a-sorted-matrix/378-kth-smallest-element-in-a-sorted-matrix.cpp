class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> >>, greater<pair<int,pair<int,int> >> >pq;
        int n = mat.size();
        for(int i=0;i<n;i++) {
            pq.push(make_pair(mat[i][0],make_pair(i,0)));
        }
        for(int i=1;i<k;i++) {
            int posx = pq.top().second.first;
            int posy = pq.top().second.second;
            pq.pop();
            if(posy<n-1) {
                pq.push(make_pair(mat[posx][posy+1],make_pair(posx,posy+1)));
            }
        }
        return pq.top().first;
    }
};