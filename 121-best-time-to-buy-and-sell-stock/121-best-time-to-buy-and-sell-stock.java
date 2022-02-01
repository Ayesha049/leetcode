class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int cur = 100001;
        for(int price: prices) {
            if(price<cur) {
                cur = price;
            } else {
                int profit = price-cur;
                maxProfit = Math.max(profit,maxProfit);
            }
        }
        return maxProfit;
    }
}