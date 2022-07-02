class Solution {
public:
    int maxArea(int h, int w, vector<int>& hs, vector<int>& vs) {
        sort(hs.begin(),hs.end());
        sort(vs.begin(),vs.end());
        long long l = hs[0];
        if(hs.size()>1) {
            for(int i=1;i<hs.size();i++) {
            l = max(l,(long long)hs[i]-hs[i-1]);
        }
        }
        l = max(l,(long long)h-hs.back());
        long long r = vs[0];
        
        if(vs.size()>1) {
            for(int i=1;i<vs.size();i++) {
            r = max(r,(long long)vs[i]-vs[i-1]);
        }
        }
        r = max(r,(long long)w-vs.back());
        return ((l%1000000007)*(r%1000000007))%1000000007;
    }
};