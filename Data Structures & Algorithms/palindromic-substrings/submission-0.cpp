class Solution {
public:

    bool is_pal( string s, int curr, int i) {
        while ( curr <= i ) {
            if ( s[curr] != s[i] ) return false;

            curr++;
            i--;
        }

        return true;
    }

    int helper ( int curr, int n , string s) {

        if ( curr == s.size() ) return 0;

        //int lol = 0;

        //if ( dp[curr] != -1 ) return dp[curr];
        int ans = 0;

        for ( int i = curr ; i < n ; i++ ) {
            string tmp =  s.substr(curr, i-curr+1);
            
            if ( is_pal(s, curr, i) ) 
            ans++;
        }

        return ans + helper(curr+1, n, s);
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        return helper(0, n, s);
    }
};
