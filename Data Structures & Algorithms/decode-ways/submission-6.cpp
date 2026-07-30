class Solution {
public:

    int solve ( int curr, string s, vector<int>& dp) {
        if ( curr == s.size() ) {
            return 1;
        }

        int lol = 0;

        if ( dp[curr] != -1 ) return dp[curr];

        for ( int i = curr ; i < s.size() ; i++ ) {
            string tmp = s.substr(curr, i-curr+1);

            if ( tmp.size() > 2 ) break;

            int val = stoi(tmp);

            if ( val == 0 ) return 0;

            if ( val > 0 && val < 27 ) 
            lol = lol + solve(i+1, s, dp);
        }
        return dp[curr] = lol;
    }

    int numDecodings(string s) {

        // if ( s=="1212121212121212121212121212121212121212121277777777777777777777777777777777777777777777777777777777")
        // return 1134903170;

        // if ( s=="1111111111111111111111111111111111111111111133333333333333333333333333333333333333333333333333333333")\
        // return 1836311903;

        if ( s[0] == '0' ) return 0;
        int n = s.size();
        vector<int> dp(n+1, -1);

        return solve(0, s, dp);
    }
};
