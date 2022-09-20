class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        if(arr.size() < k) return 0;
        double sum = 0;
        for(int i=0;i<k;i++) sum+=arr[i];
        int ans = 0;
        if(sum/k >= t) ans++;
        int l = 0;
        for(int r=k;r<arr.size();r++) {
            sum+=arr[r];
            sum-=arr[l++];
            if(sum/k >= t) ans++;
        }
        return ans;
    }
};