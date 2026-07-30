class Solution {
public:

    int solve ( int i , int n , bool buy, vector<int>& prices, vector<vector<int>>& dp) {
        if ( i >= n ) return 0;

        if ( dp[i][buy] != -1 ) return dp[i][buy];

        int profit = 0;

        //buy
        if ( buy ) {
            //
            int take = -prices[i] + solve (i+1, n, false, prices, dp);
            int hold = solve(i+1, n, true, prices, dp);

             return dp[i][buy] = max(take, hold);
        }

        //sell
        if ( !buy ) {
           
            int sell = prices[i] + solve(i+2, n, true, prices, dp);
            int holup = solve(i+1, n, false, prices, dp);

            return dp[i][buy] = max(sell, holup);
        }

        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        int ans = 0;

        for ( int i = 0 ; i < n ; i++ ) {
            ans = max(ans, solve(i, n, true, prices, dp));
        }

        return ans;
    }
};
