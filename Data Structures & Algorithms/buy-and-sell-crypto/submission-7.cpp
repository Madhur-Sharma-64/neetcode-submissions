class Solution {
public:
int n;

    int profit ( vector<int>& prices, int i, bool should_buy, vector<vector<int>>& dp) {
        if ( i >= n ) return 0;

        if ( dp[i][should_buy] != -1 ) return dp[i][should_buy];

        int maxb = 0;
        int maxs = 0;
        if ( should_buy ) {
            int buy = profit(prices, i+1, false, dp) - prices[i];
            int hold = profit(prices, i+1, true, dp);

            maxb = max(buy, hold);
        } else {
            int sell = prices[i];
            int wait = profit(prices, i+1, false, dp);

            maxs = max(sell, wait);
        }

        return dp[i][should_buy] = maxb + maxs;

    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return profit(prices, 0, true, dp);
    }
};
