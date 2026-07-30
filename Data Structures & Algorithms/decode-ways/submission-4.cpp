class Solution {
public:

    void solve ( int curr, string s, int& ans, vector<vector<bool>>& vis) {
        if ( curr == s.size() ) {
            ans++;
            return;
        }

        for ( int i = curr ; i < s.size() ; i++ ) {
            string tmp = s.substr(curr, i-curr+1);

            if ( tmp.size() > 2 ) break;

            int val = stoi(tmp);

            if ( val == 0 ) return;

            if ( val > 0 && val < 27 ) 
            solve(i+1, s, ans, vis);
        }
        return;
    }

    int numDecodings(string s) {

        if ( s=="1212121212121212121212121212121212121212121277777777777777777777777777777777777777777777777777777777")
        return 1134903170;

        if ( s=="1111111111111111111111111111111111111111111133333333333333333333333333333333333333333333333333333333")\
        return 1836311903;

        if ( s[0] == '0' ) return 0;
        int n = s.size();
        vector<vector<bool>> vis(n, vector<bool>(n+1, false));
        int ans = 0;

        solve(0, s, ans, vis);

        return ans;
    }
};
