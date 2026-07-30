class Solution {
public:

int n;
int m;

    int diff ( int currx, int curry, string& word1, string& word2, vector<vector<int>>& dp ) {
        if ( currx == n ) return word2.size() - curry;
        if ( curry == m ) return word1.size() - currx;

        int changes = 0;

        if ( dp[currx][curry] != -1 ) return dp[currx][curry];

        if ( word1[currx] == word2[curry] ) {
            changes = diff(currx+1, curry+1, word1, word2, dp);
        }
        else {
            changes = 1 + min({diff(currx+1, curry, word1, word2, dp), diff(currx, curry+1, word1, word2, dp), diff(currx+1, curry+1, word1, word2, dp)});
        }

        return dp[currx][curry] = changes;
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return diff(0, 0, word1, word2, dp);
    }
};
