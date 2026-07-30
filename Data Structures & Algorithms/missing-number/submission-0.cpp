class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int exp = ( n * (n+1) )/2;
        int exx = ( n * (n-1) )/2;

        int sum = 0;

        for ( int i = 0 ; i < nums.size() ; i++ ) sum += nums[i];

        if ( exx-sum > 0 ) return exx-sum;

        return exp-sum;
    }
};
