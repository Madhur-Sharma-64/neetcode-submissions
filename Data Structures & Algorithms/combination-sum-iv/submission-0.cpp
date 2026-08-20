class Solution {
public:
int n;

    int dfs(vector<int>& nums, int target, vector<int>& memo) {

        if ( target == 0 ) {
            return 1;
        }
        if ( target < 0 ) return 0;

        if ( memo[target] != -1 ) return memo[target];

        int ans = 0;
        for ( int num : nums ) {
            if ( target < 0 ) break;

            ans += dfs(nums, target-num, memo);

        }

        return memo[target] = ans;
        
    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> memo(target+1, -1);

        return dfs(nums, target, memo);
    }
};