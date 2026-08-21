class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = INT_MIN;

        for ( int& w : weights ) {
            l = max(l, w);
        }

        int r = 50000;

        int ans = 0;

        while ( l <= r ) {
            int m = (r+l)/2;

            int sum = 0;
            int d = 0;

            for ( int& w : weights ) {
                sum += w;
                if (sum > m) {
                    d++;
                    sum = w;
                }
                
            }

            if ( sum > 0 ) d++;

            if ( d <= days ) {
                ans = m;
                r = m-1;
            } else l = m+1;
        }

        return ans;

    }
};