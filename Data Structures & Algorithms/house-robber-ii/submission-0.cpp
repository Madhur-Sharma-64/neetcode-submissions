class Solution {
public:
    int rob(vector<int>& nums) {
        if ( nums.size() == 1 ) return nums[0];
        if ( nums.size() == 2 ) return max(nums[0], nums[1]);
        if ( nums.size() == 3 ) return max(max(nums[0], nums[1]), nums[2]);

        int a = nums[0];
        int b = nums[1];

        int ans1 = 0;
        for ( int i = 2 ; i < nums.size() - 1 ; i++ ) {
            ans1 = max(a, b);
            b = a + nums[i];
            a = ans1;
        }
        ans1 = max(a, b);

        a = nums[1];
        b = nums[2];

        int ans2 = 0;

        for ( int i = 3 ; i < nums.size() ; i++ ) {
            ans2 = max(a, b);
            b = a + nums[i];
            a = ans2;
        }
        ans2 = max(a, b);

        return max(ans1, ans2);
    }
};
