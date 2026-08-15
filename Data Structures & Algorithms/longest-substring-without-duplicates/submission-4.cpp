class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if ( n < 2 ) return n;
        int len = 0;
        int l = 0;
        int r = 1;
        int curr = 1;

        unordered_map<char, int> mp;
        mp[s[l]] = 1;


        while ( r < n ) {
            mp[s[r]]++;

            while ( mp[s[r]] > 1 ) {
                mp[s[l]]--;
                l++;
            }

            curr = r-l+1;
            r++;

            len = max(curr, len);
        }
        len = max(curr, len);
        return len;
    }
};
