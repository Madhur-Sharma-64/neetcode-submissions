class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxPile = 0;

        for (int i = 0; i < piles.size(); i++) {
            if (maxPile < piles[i])
                maxPile = piles[i];
        }

        int low = 1;
        int high = maxPile;
        int ans = maxPile;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long sum = 0;

            for (int i = 0; i < piles.size(); i++) {
                int t = piles[i] / mid;
                if (piles[i] % mid != 0)
                    t++;
                sum += t;
            }

            if (sum <= h) {
                ans = mid;      // speed works
                high = mid - 1; // try smaller speed
            }
            else {
                low = mid + 1;  // speed too slow
            }
        }

        return ans;
    }
};