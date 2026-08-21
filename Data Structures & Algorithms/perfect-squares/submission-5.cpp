class Solution {
public:

    int dfs(int target, vector<int>& sqr, vector<int>& memo) {
        if ( target == 0 ) {
            return 0;
        } else if ( target < 0 ) return 1e9;

        if ( memo[target] != -1 ) return memo[target];

        int ans = 1e9;
        for ( int i = sqr.size()-1 ; i>= 0 ; i-- ) {
            if ( sqr[i] > target ) continue;

            ans = min(ans, 1 + dfs(target-sqr[i], sqr, memo));
        }

        return memo[target] = ans;
    }

    int numSquares(int n) {
        vector<int> sqr;

        int i = 1;
        while ( i*i <= n ) {
            int cur = i*i;

            sqr.push_back(cur);

            i++;
        }

        vector<int> memo(n+1, -1);
        return dfs(n, sqr, memo);
    }
};