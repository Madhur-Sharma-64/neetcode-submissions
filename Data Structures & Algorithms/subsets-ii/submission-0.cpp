class Solution {
public:

    void getsubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& res) {
        if ( i == nums.size() ) {
            res.push_back(ans);
            return;
        }

        //include
        ans.push_back(nums[i]);
        getsubsets(nums, ans, i+1, res);

        //backtrack
        ans.pop_back();

        //exclude
        int count = i + 1;
        while ( count < nums.size() && nums[count] == nums[count-1] ) count++;
        getsubsets(nums, ans, count, res);

    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> ans;

        getsubsets(nums, ans, 0, res);
        return res;
    }
};