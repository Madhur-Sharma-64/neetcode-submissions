class StockSpanner {
public:
stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if ( st.empty() ) {
            st.push(price);
            return 1;
        } else {
            stack<int> tmp = st;
            int days = 0;
            while ( !tmp.empty() ) {
                if ( price >= tmp.top() ) {
                    days++;
                } else {
                    st.push(price);
                    return ++days;
                }
                tmp.pop();
            }
        }

        st.push(price);

        return st.size();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */