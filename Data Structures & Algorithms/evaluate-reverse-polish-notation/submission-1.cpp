class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack <int> st;
        for ( int i = 0 ; i < tokens.size() ; i++ ){
            string c = tokens[i];
            if ( c == "+" ){
                int sum = st.top();
                st.pop();
                sum += st.top();
                st.pop();
                st.push(sum);
            }
            else if ( c == "-" ){
                int sub = st.top();
                st.pop();
                sub = st.top() - sub;
                st.pop();
                st.push(sub);
            }
            else if ( c == "*" ){
                int prod = st.top();
                st.pop();
                prod *= st.top();
                st.pop();
                st.push(prod);
            }
            else if ( c == "/" ){
                int div = st.top();
                st.pop();
                div = st.top()/div;
                st.pop();
                st.push(div);
            }
            else {
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
