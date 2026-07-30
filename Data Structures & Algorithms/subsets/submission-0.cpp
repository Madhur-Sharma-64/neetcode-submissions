class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans = {{}};

        for ( int i = 0 ; i < nums.size() ; i++ ) {
            int len = ans.size();
            for ( int j = 0 ; j < len ; j++ ) {
                vector<int> test;
                test = ans[j];
                test.push_back(nums[i]);
                ans.push_back(test);
            }
        }

        
        return ans;
    }
};
