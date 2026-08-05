class Solution {
public:
    int n;
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

    void solve ( int i, string& ans, string& digits ) {
        if ( i == n) {
            res.push_back(ans);
            return;
        }
        if ( i >= n ) return;
        int id = digits[i] - '0';

        for ( int cur = 0 ; cur < digitToChar[id].size() ; cur++) {
            ans.push_back(digitToChar[id][cur]);
            
            solve(i+1, ans, digits);
            ans.pop_back();
        }
        //ans.pop_back();
    }

    vector<string> letterCombinations(string digits) {
        if ( digits.empty() ) return {};

        n = digits.size();
        string ans;

        solve(0, ans, digits);

        return res;

    }
};
