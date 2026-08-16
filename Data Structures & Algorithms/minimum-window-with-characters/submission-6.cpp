class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int have = 0;

        if ( m > n ) return "";

        int l = 0;
        int r = 0;

        unordered_map<char, int> tkb;
        for (char& c : t ) 
        tkb[c]++;

        int need = tkb.size();

        unordered_map<char, int> skb;
       // skb[s[0]]++;

        string ans;
        int minlen = INT_MAX;

        int idx = 0;
        int ws = 0;

        while ( r < n ) {
            ws = r-l+1;  //window size
            char c = s[r];

            skb[c]++;     
            if ( tkb.count(c) && tkb[c] == skb[c] ) have++;

            while ( have == need ) {
                ws = r-l+1;
                if ( ws < minlen ) {
                    minlen = ws;
                    idx = l;
                }

                skb[s[l]]--;

                if ( tkb.count(s[l]) && skb[s[l]] < tkb[s[l]] ) have--;

                l++;
            }
            r++;
        }

        if ( minlen == INT_MAX ) return "";

        return s.substr(idx, minlen);
    }
};
