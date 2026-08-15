class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for ( int& num : nums ) s.insert(num);

        int ans = 0;

        for ( int num : nums ) {
            if ( s.find(num-1) == s.end() ) {
                int l = 1;
                int c = 1;
                while ( s.find(num+c) != s.end() ) {
                    l++;
                    c++;
                }
                ans = max(ans, l);
            }
        }

        return ans;
        
    }
};
