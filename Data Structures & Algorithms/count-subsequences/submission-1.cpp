class Solution {
public:

    int help ( int currs, int currt, int n, string& s, string& t, vector<vector<int>>& dp, vector<vector<bool>>& vis) {
        if ( currt == t.size() ) return 1;

        if ( currs >= n ) return 0;

        if ( dp[currs][currt] != -1 ) return dp[currs][currt];

        int sbsq = 0;
        vis[currs][currt] = true;

        if ( s[currs] == t[currt] ) {
            sbsq += help(currs + 1, currt+1, n, s, t, dp, vis) + help(currs+1, currt, n, s, t, dp, vis);
        }
        else {
            if ( currs+1 < n && vis[currs+1][currt] == false )
            sbsq += help(currs+1, currt, n, s, t, dp, vis);
        }

        return dp[currs][currt] = sbsq;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int ans = 0;

        vector<vector<int>> dp( n, vector<int>(n, -1));
        vector<vector<bool>> vis( n, vector<bool>(n, false));

        //for ( int i = 0 ; i < n ; i++ ) {
            //if ( s[i] == t[0] ) {
                ans += help(0, 0, n, s, t, dp, vis);
            //}
        //}
        return ans;
    }
};
