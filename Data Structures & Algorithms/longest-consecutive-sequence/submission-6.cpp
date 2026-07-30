class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int len = 0;

        unordered_map <int, int> map;

        for ( int i = 0 ; i < nums.size() ; i++ )
        map[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++) {

            if (map.find(nums[i] - 1) != map.end())
            continue;

            int current = nums[i];
            int length = 1;

            while (map.find(current + 1) != map.end()) {
                current++;
                length++;
            }   

            len = max(len, length);
        }

        return len;
    }
};
