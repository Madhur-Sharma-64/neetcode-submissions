class Solution {
public:


    void helper( int i, int j, string& s, vector<string>& res, int n) {
        if ( i > n || j > n ) return;

        if ( i == n && j == n ) {
            res.push_back(s);
            return;
        }

        //(
        if ( i < n ) {
            s.push_back('(');
            helper(i+1, j, s, res, n);
            s.pop_back();
        }
       
        if ( i > j ) {
            s.push_back(')');
            helper(i, j+1, s, res, n);
            s.pop_back();
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> res;

        helper(0, 0, s, res, n);

        return res;
        
    }
};
