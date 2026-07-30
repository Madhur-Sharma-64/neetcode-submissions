class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            int idx = (left + right) / 2;

            if (nums[idx] == target)
                return idx;

            else if (nums[idx] < target)
                left = idx + 1;

            else
                right = idx - 1;
        }

        return -1;
    }
};