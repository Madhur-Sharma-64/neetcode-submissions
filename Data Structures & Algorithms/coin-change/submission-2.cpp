class Solution {
public:

    int solve ( int i, int n, vector<int>& coins, vector<vector<int>>& dp, int amount )  {
        if ( amount == 0 ) return 0;

        if ( i >= n ) return 1e9;

        if ( dp[i][amount] != -1 ) return dp[i][amount];

        int take = 1e9;
        if ( amount >= coins[i] ) take = 1 + solve(i, n, coins, dp, amount-coins[i]);

        int nott = solve(i+1, n, coins, dp, amount);

        return dp[i][amount] = min(take, nott);
    }

    int coinChange(vector<int>& coins, int amount) {
        if ( amount == 0 ) return 0;
        int n = coins.size();

        vector<vector<int>> dp ( n, vector<int>(amount+1, -1));
        sort(coins.rbegin(), coins.rend());

        int ans = solve(0, n, coins, dp, amount);

        if ( ans >= 1e9 ) return -1;

        return ans;
    }
};
