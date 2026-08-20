class Solution {
public:

    int dfs(int cur, int n) {
        //if ( n <= 4 ) return n;

        if ( min(cur, n) == 0 ) return 1;

        if ( cur > n ) return dfs(n, n);

        return max(cur*dfs(cur, n-cur), dfs(cur-1, n));
    }

    int integerBreak(int n) {
        return dfs(n-1, n);
    }
};