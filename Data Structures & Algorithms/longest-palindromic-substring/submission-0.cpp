class Solution {
public:

    bool solve(int i, int j, string& s, vector<vector<int>>& dp) {
        
        if (i >= j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] != s[j]) return dp[i][j] = false;

        return dp[i][j] = solve(i+1, j-1, s, dp);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(i, j, s, dp) && j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};