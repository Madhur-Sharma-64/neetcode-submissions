class Solution {
public:

    int sqr ( int n ) {
        return n*n;
    }


    bool isHappy(int n) {
        
        //int sum = 0;
        while ( n > 9 ) {
            int sum = 0;
            while ( n > 0 ) {
                sum += sqr(n%10);
                n = n/10;
            }
            n = sum;
        }
        if ( n == 1 || n == 7 ) return true;

        return false;
    }
};
