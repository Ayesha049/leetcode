class Solution {
public:
    int replaceCount (vector<int>& A, vector<int>& B, int val) {
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == val) continue;
            if (B[i] == val) {
                ans++;
                continue;
            }
            return -1;
        }
        return ans;
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans = -1;
        int count = replaceCount(A,B,A[0]);
        if (count!=-1) ans = count;
        
        count = replaceCount(A,B,B[0]);
        if (count!=-1) {
            if(ans == -1) ans = count;
            else ans = min(ans,count);
        }
        
        count = replaceCount(B,A,A[0]);
        if (count!=-1) {
            if(ans == -1) ans = count;
            else ans = min(ans,count);
        }
        
        count = replaceCount(B,A,B[0]);
        if (count!=-1) {
            if(ans == -1) ans = count;
            else ans = min(ans,count);
        }
        
        return ans;
        
    }
};