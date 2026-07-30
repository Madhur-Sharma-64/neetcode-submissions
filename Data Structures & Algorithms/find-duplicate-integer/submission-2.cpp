class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();
        
        vector<int> frq(n,0);

        for ( int i = 0 ; i < n ; i++ )
        frq[nums[i]]++;

        for ( int i = 1 ; i <= n ; i++ ) {
            if ( frq[i] > 1 ) return i;
        }
        
        return -1;

    }
};
