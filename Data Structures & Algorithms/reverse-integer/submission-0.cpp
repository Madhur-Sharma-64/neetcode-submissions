class Solution {
public:
    int reverse(int x) {
        int flag = 0 ;
        int no = 0 ;
        if ( x < 0 && x > INT_MIN ){
            flag = 1;
            x = -x;
        }
        while ( x > 0 ){
            if ( no > INT_MAX/10 || (no == INT_MAX && x%10 > 7) )
            return 0;

            //if ( no < INT_MIN/10 && x)
            no = no*10 + x%10;

            // if ( no > INT_MAX/10 && x%10 > 7)
            // return 0;

            x = x/10;
        }
        if ( flag == 1 ){
            return (no*(-1));
        }
        else
        return no;
    }
};