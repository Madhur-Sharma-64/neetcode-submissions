class Solution {
public:

    bool is_pal( string s, int curr, int i, vector<vector<bool>>& dp) {

        if ( dp[curr][i] == true ) return true;

        int left = curr;
        int right = i;

        while ( left <= right ) {
            if ( s[left] != s[right] ) return false;

            left++;
            right--;
        }

        return dp[curr][i] = true;
    }

    int helper ( int curr, int n , string s, vector<vector<bool>>& dp) {

        if ( curr == s.size() ) return 0;

        //int lol = 0;

        //if ( dp[curr] != -1 ) return dp[curr];

        int ans = 0;

        for ( int i = curr ; i < n ; i++ ) {
            string tmp =  s.substr(curr, i-curr+1);
            
            if ( is_pal(s, curr, i, dp) ) 
            ans++;
        }

        return ans + helper(curr+1, n, s, dp);
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));

        return helper(0, n, s, dp);
    }
};
