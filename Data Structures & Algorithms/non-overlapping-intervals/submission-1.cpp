class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int back = INT_MIN;
        int ans = 0;

        for ( int i = 0 ; i < n ; i++ ) {
            int st = intervals[i][0];
            int end = intervals[i][1];

            if ( st >= back ) {
                back = end;
            } else {
                ans++;
                back = min(back, end);
            }
        }

        return ans;

    }
};
