class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        n = n/3;

        unordered_map<int, int> mp;
        for ( int& num : nums ) {
            mp[num]++;
        }

        vector<int> ans;
        for ( auto& x : mp ) {
            if ( x.second > n ) ans.push_back(x.first);
        }
        
        return ans;
    }
};