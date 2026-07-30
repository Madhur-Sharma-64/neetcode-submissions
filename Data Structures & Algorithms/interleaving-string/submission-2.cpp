class Solution {
public:

    bool solve ( int currx, int curry, int i, int n, int m, string& s1, string& s2, string& s3) {
        if ( currx > n && curry > m ) return false;
        if ( i == n+m ) return true;
        bool ans = false;

        if ( s1[currx] == s3[i] ) {
            ans = ans || solve(currx+1, curry, i+1, n, m, s1, s2, s3);
        }

        if ( s2[curry] == s3[i] ) {
            ans = ans || solve(currx, curry+1, i+1, n, m, s1, s2, s3);
        }

        return ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        string s;

        if ( s3.size() != n+m ) return false;

        return solve(0, 0, 0, n, m, s1, s2, s3);

    }
};
