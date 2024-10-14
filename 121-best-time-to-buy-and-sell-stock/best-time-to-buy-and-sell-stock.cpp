class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int l = 0;
        int r = 1;

        while(r < prices.size()){
            if(prices[l] > prices[r]){
                l = r;
                r++;
                continue;
            }
            if(maxProfit < prices[r] - prices[l]){
                maxProfit = prices[r] - prices[l];
            }

            r++;
        }

        return maxProfit;
    }
};