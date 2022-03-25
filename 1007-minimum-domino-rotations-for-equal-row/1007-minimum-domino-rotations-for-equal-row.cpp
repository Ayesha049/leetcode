class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int top = 0;
        int bottom = 0;
        int swapTop = 1;
        int swapBottom = 1;
        //top calculation
        int n = tops.size();
        int val = tops[0];
        for(int i=1;i<n;i++) {
            if(val != tops[i]) {
                if(val != bottoms[i]) {
                    top = -1;
                    break;
                } else {
                    top++;
                }
            }
        }
        
        //swap top calculation
        val = bottoms[0];
        for(int i=1;i<n;i++) {
            if(val != tops[i]) {
                if(val != bottoms[i]) {
                    swapTop = -1;
                    break;
                } else {
                    swapTop++;
                }
            }
        }
        val = bottoms[0];
        //bottom
        for(int i=1;i<n;i++) {
            if(val != bottoms[i]) {
                if(val != tops[i]) {
                    bottom = -1;
                    break;
                } else {
                    bottom++;
                }
            }
        }
        
        //swapBottom
        val = tops[0];
        for(int i=1;i<n;i++) {
            if(val != bottoms[i]) {
                if(val != tops[i]) {
                    swapBottom = -1;
                    break;
                } else {
                    swapBottom++;
                }
            }
        }
        int bestTop = top == -1 && swapTop == -1 ? -1 : min(top == -1 ? INT_MAX : top, swapTop == -1 ? INT_MAX : swapTop);
        int bestBottom = bottom == -1 && swapBottom == -1 ? -1 : min(bottom == -1 ? INT_MAX : bottom, swapBottom == -1 ? INT_MAX : swapBottom);
        if(bestTop == -1) return bestBottom;
        if(bestBottom == -1) return bestTop;
        return min(bestTop,bestBottom);
    }
};