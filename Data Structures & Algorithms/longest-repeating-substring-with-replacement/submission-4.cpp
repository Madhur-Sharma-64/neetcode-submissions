class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int ans = 0;
        int dw = 0;
        int n = s.size();
        unordered_map<char, int> window;

        for ( int r = 0 ; r < n ; r++ ) {
            window[s[r]]++;
            dw = max(dw, window[s[r]]);

            while ( r-l+1 - dw > k ) {
                //if (s[l] != s[r] ) 
                window[s[l]]--;

                l++;
            }
            // if ( s[r] != s[l] ) {
            //     window ++;
            // }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
