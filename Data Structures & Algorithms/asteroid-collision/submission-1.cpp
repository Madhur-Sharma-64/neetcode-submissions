class Solution {
public:

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for ( int& a : asteroids ) {

            if ( st.empty() ) {
                st.push(a);
                continue;
            } 

            while (!st.empty() && a < 0 && st.top() > 0 ) {
                if ( abs(a) < abs(st.top()) ){
                    a = 0;
                    break;
                } else if (!st.empty() && abs(a) == abs(st.top()) ) {
                    a = 0;
                    st.pop();
                    break;
                } else {
                    if ( !st.empty() )
                    st.pop();
                }
            }

            if (a != 0) st.push(a);
        }

        vector<int> ans;
        while ( !st.empty() ) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};