class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1]>=b[1];
    }
    int maximumUnits(vector<vector<int>>& boxes, int trk) {
        sort(boxes.begin(),boxes.end(), comp);
        int ans = 0;
        for(int i=0;i<boxes.size();i++) {
            if(trk<=0) break;
            int bx = boxes[i][0] > trk ? trk : boxes[i][0];
            ans+=(bx*boxes[i][1]);
            trk-=bx;
        }
        return ans;
    }
};