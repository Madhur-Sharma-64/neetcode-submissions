class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        bool lolu = false;
        for ( int i = 0 ; i < digits.size() ; i++ ){
            if ( digits[i] != 9 ) 
            lolu = true;
        }
        if ( lolu == false ){
            for ( int i = 0 ; i < digits.size() ; i++ ) {
                if ( i == 0 )
                digits[i] = 1;

                else
                digits[i] = 0;
            }
            digits.push_back(0);
            return digits;
        }

        for ( int i = digits.size() - 1 ; i >= 0 ; i-- ) {
            int sum = digits[i] + carry;
            if ( i == digits.size() - 1 )
            digits[i] = (++sum)%10;

            else
            digits[i] = sum%10;

            carry = sum / 10;
        }
        return digits;
    }
};
