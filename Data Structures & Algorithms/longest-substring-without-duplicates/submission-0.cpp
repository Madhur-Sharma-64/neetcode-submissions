class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       // unordered_map <char, int> mp;
        int len = 0;
        for ( int i = 0 ; i < s.size() ; i++ ){

            int count = 0;
            unordered_map <char, int> mp;

            for ( int j = i ; j < s.size() ; j++ ){

                if ( mp.find(s[j]) != mp.end() )
                break;

                mp[s[j]]++;
                count++;
            }

            if ( count > len )
            len = count;

           // return len;

        }
        return len;
    }
};
