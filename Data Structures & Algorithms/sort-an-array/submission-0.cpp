class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int> > mh;
        for ( int& n : nums ) mh.push(n);

        vector<int> sorted;
        while ( !mh.empty() ) {
            sorted.push_back(mh.top());
            mh.pop();
        }

        return sorted;
    }
};