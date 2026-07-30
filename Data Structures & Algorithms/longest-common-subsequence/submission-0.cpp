class Solution {
public:

    int solve( int i, int j , int n, int m, vector<vector<int>>& dp, string t1, string t2) {
        if ( i == n || j == m ) return 0;

        if ( dp[i][j] != -1 ) return dp[i][j];

        if ( t1[i] == t2[j] ) {
            dp[i][j] = 1 + solve(i+1, j+1, n, m, dp, t1, t2);
        }

        else {
            dp[i][j] = max(solve(i+1, j, n, m, dp, t1, t2), solve(i, j+1, n, m, dp, t1 ,t2));
        }

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, n, m, dp, text1, text2);
    }
};
