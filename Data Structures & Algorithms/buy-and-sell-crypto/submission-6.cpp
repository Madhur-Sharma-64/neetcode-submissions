class Solution {
public:
int n;

    int profit ( vector<int>& prices, int i, bool should_buy) {
        if ( i >= n ) return 0;

        int maxb = 0;
        int maxs = 0;
        if ( should_buy ) {
            int buy = profit(prices, i+1, false) - prices[i];
            int hold = profit(prices, i+1, true);

            maxb = max(buy, hold);
        } else {
            int sell = prices[i];
            int wait = profit(prices, i+1, false);

            maxs = max(sell, wait);
        }

        return maxb + maxs;

    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();

        return profit(prices, 0, true);
    }
};
