class Solution {
public:
    void sortColors(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int> > mh;
        for ( int& n : nums ) mh.push(n);

        for ( int i = 0 ; i < nums.size() ; i++ ) {
            nums[i] = mh.top();
            mh.pop();
        }
    }
};