class Solution {
public:
    int jump(vector<int>& nums) {
        if ( nums.size() == 1 ) return 0;
        int ans = 0;
        int farthest = 0;

        for ( int i = 0 ; i < nums.size() ; i++ ) {
            farthest = max(farthest + nums[farthest], i+nums[i]);
            ans++;

            if ( farthest >= nums.size() - 1 ) return ans;
        }

        return ans;
    }
};
