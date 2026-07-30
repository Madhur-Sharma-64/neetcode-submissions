class Solution {
public:

    int helper(int curr, int n, string &s, vector<vector<bool>>& dp) {

        if (curr == n) return 0;

        int ans = 0;

        for (int i = curr; i < n; i++) {
            if (dp[curr][i])
                ans++;
        }

        return ans + helper(curr + 1, n, s, dp);
    }

    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Precompute all palindromes
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j]) {

                    if (j - i <= 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        return helper(0, n, s, dp);
    }
};