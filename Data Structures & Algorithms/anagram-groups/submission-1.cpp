class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map < string, vector<string> > mp;

        for ( int i = 0 ; i < strs.size() ; i++ ){

            string copy = strs[i];
            
            for ( int j = 0 ; j < (int)copy.size() - 1 ; j++ ){
                for ( int k = 0 ; k < (int)copy.size() - j - 1 ; k++ ){

                    if ( copy[k] > copy[k+1] ){
                        char tmp = copy[k];
                        copy[k] = copy[k+1];
                        copy[k+1] = tmp;
                    }
                }
            }

            mp[copy].push_back(strs[i]);
   
        }
       // int count = 0;
        for ( auto x : mp ){
            ans.push_back(x.second);
        }

        return ans;
    }
};
