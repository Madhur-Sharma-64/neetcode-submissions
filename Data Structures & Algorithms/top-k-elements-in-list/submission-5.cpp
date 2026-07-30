class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        vector<int> ans(k);
       // vector<int> count(k);
        
        for ( int i = 0 ; i < nums.size() ; i++ ){
            mp[nums[i]]++;
        }

        for ( int j = 0 ; j < k ; j++ ){
            int max = 0;
            int no = 0;
            
            //if ( j > 0 ) {
                // for ( auto x : mp ){
                //     if ( x.second > max ){
                //         max = x.second;
                //         no = x.first;
                //     }
                // }
            //}
            //else {
                for ( auto x : mp ){
                    if ( x.second > max ){
                        max = x.second;
                        no = x.first;
                    }
                }
            //}
            ans[j] = no;
            mp.erase(no);
           // count[j] = max;
        }
        return ans;
    }
};
