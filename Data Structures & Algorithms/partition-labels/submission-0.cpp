class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> mp;

        for ( int i = 0 ; i < s.size() ; i++ ) {
            mp[s[i]].push_back(i);
        }

        vector<int> ans;
        int st = 0, end = 0;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            char c = s[i];
            end = max(end, mp[c].back());
            if ( end == i ) {
                ans.push_back(end-st+1);
                st = i+1;
            }
            
        }

        return ans;
    }
};
