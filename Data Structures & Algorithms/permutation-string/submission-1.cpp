class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if ( n > m ) return false;

        unordered_map<char, int> mp;
        for ( char& c : s1) 
            mp[c]++;

        unordered_map<char, int> tmp;
        int r = n-1;
        int l = 0;

        while ( l <= r ) {
            tmp[s2[l]]++;
            l++;
        }
        l = 0;
       
        while ( r < m ) {
            if ( tmp == mp ) return true;

            tmp[s2[l]]--;
            if ( tmp[s2[l]] == 0 ) tmp.erase(s2[l]);

            l++;
            r++;
            if ( r != m)
            tmp[s2[r]]++;
        }

        return false;
        
    }
};
