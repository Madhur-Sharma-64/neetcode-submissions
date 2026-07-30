class Solution {
public:
    bool isPalindrome(string s) {
        string curr;
        string rev;
        for ( int i = 0 ; i < s.size() ; i++ ){
            if ( (s[i] >= 'a' && s[i] <= 'z') ){
                curr.push_back(s[i]);
            }
            else if ( s[i] >= 'A' && s[i] <= 'Z' ){
                curr.push_back(s[i]+32);
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                curr.push_back(s[i]);
            }
        }

        for ( int i = 0 ; i < curr.size() ; i++ )
        rev.push_back(curr[curr.size()-1-i]);

        for ( int i = 0 ; i < curr.size() ; i++ ){
            if ( rev[i] != curr[i] )
            return false;
        }
        return true;
    }
};
