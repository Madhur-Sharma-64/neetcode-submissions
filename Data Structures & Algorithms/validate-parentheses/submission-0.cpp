class Solution {
public:
    bool isValid(string s) {
        if ( s.size()%2 == 1 ) return false;

        if ( s.size() == 0 ) return true;

        stack<char> st;

        for ( char c : s ) {
            if (st.empty())  {
                st.push(c);
                continue;
            }

            if ( st.top() == '[' && c == ']' ) st.pop();
            else if ( st.top() == '(' && c == ')' ) st.pop();
            else if ( st.top() == '{' && c == '}' ) st.pop();

            else st.push(c);

        }
        if ( st.empty() ) return true;

        return false;
    }
};
