class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = k-1;

        vector<int> ans;

        while ( right < nums.size() ) {
            int st = left;
            int end = right;
            int MAx = INT_MIN;

            while ( st <= end ) {
                if ( nums[st] < nums[end] ){
                    MAx = max(MAx, nums[end]);
                    st++;
                }

                else {
                    MAx = max(MAx, nums[st]);
                    end--;
                }
            }
            ans.push_back(MAx);
            left++;
            right++;
        }

        return ans;
    }
};
