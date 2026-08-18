class Solution {
public:
int n;

    int solve ( int i, bool& zero, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if ( amount == 0 ) {
            zero = true;
            return 0;
        }

        if ( i >= n || amount < 0 ) return 1e9;

        if ( dp[i][amount] != -1 ) return dp[i][amount];

        int take = 1e9;
        if ( amount >= coins[i] )
        take = 1 + solve(i, zero, coins, amount-coins[i], dp);

        int not_take = solve(i+1, zero, coins, amount, dp);

        return dp[i][amount] = min(take, not_take);

    }

    int coinChange(vector<int>& coins, int amount) {
        if ( amount == 0 ) return 0;
        bool zero = false;

        n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = solve(0, zero, coins, amount, dp);

        if ( !zero ) return -1;

        return ans;
    }
};
