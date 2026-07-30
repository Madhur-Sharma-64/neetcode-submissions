class Solution {
public:

    int solve ( int i, int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        if ( i >= n ) return 0;
        if ( amount < 0 ) return 0;

        if ( amount == 0 ) return 1;

        if ( dp[i][amount] != -1 ) return dp[i][amount];

        int take = 0;
        take += solve(i, n, amount-coins[i], coins, dp);

        int nott = 0;
        nott += solve(i+1, n, amount, coins, dp);

        return dp[i][amount] = take + nott;

    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.rbegin(), coins.rend());

        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        return solve(0, n, amount, coins, dp);

    }
};
