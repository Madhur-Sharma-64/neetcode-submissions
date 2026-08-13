class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int max = 0;

        for ( int i = 0 ; i < s.size() ; i++ ) {
            char c = s[i];

            if ( c == '(' ){
                low ++;
                max ++;
            } else if (c == ')' ) {
                low--;
                max--;
            } else {
                low--;
                max++;
            }

            if ( low < 0 ) low = 0;

            if ( max < 0 ) return false;

        } 

        return low == 0;
    }
};
