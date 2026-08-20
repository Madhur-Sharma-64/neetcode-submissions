class Solution {
public:

    int dfs(int i, int target, vector<int>& sqr, vector<vector<int>>& memo) {

        if ( target == 0 ) {
            return 0;
        } else if ( target < 0 ) return 1e9;

        if ( i < 0 ) return 1e9;

        if ( memo[i][target] != -1 ) return memo[i][target];

        int take = 1e9;
        for ( int cur = i ; cur >= 0 ; cur-- ) {

            if ( target < sqr[cur] ) continue;

            take = min(take, 1 + dfs(cur, target-sqr[cur], sqr, memo));

        }

        return memo[i][target] = take;
    }

    int numSquares(int n) {
        vector<int> sqr;

        int i = 1;
        while ( i*i <= n ) {
            int cur = i*i;

            sqr.push_back(cur);

            i++;
        }

        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        return dfs(sqr.size()-1, n, sqr, memo);
    }
};