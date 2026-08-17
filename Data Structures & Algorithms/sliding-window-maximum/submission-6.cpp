class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int total_w = n-k+1;

        if ( n == 1 ) return nums;

        int l = 0;
        int r = 0;

        deque<pair<int, int>> dq;

       // dq.push_front({nums[l], 0});
        int grt = INT_MIN;
        vector<int> ans;

        while ( r < n ) {
            int ws = r-l+1;

            while (!dq.empty() && dq.back().first < nums[r]) dq.pop_back();

             dq.push_back({nums[r], r});

            while (!dq.empty() && l > dq.front().second ) dq.pop_front();

            grt = max(grt, dq.front().first);

            if ( ws == k ) {
                ans.push_back(grt);
                grt = INT_MIN;
                l++;
            } 
            

            r++;
        }

        return ans;
    }
};
