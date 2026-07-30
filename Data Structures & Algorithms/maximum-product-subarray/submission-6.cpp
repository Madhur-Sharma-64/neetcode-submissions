class Solution {
public:

    int prod ( int i, int n, vector<int>& nums, vector<int>& dp, vector<int>& dpmin, vector<bool>& vis) {
        if ( i == n-1 ) return dpmin[i] = nums[i];

        if ( vis[i] == true ) return dp[i];

        vis[i] = true;
        int ma = prod(i+1, n, nums, dp, dpmin, vis);
        int mi = dpmin[i+1];

        int maX = 1;
        maX = max({nums[i], ma*nums[i], mi*nums[i]});

        int miN = -1;
        miN = min({nums[i], ma*nums[i], mi*nums[i]});

        dpmin[i] = miN;

        return dp[i] = maX;

    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;

        vector<int> dp(n, 0);
        vector<int> dpmin(n, 0);
        vector<bool> vis(n, false);

        for ( int i = 0 ; i < n ; i++ ) {
            res = max(res, prod(i, n, nums, dp, dpmin, vis));
        }

        return res;

    }
};
