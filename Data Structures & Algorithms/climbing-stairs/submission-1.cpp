class Solution {
public:
    int climbStairs(int n) {
        if ( n < 3 ) return n;

        int first = 1;
        int second = 2;

        int total = 0;

        for ( int i = 0 ; i < n - 2 ; i++ ) {
            total = first + second;
            first = second;
            second = total;
        }

        return total;

    }
};
