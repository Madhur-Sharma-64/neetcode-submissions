class MinStack {
public:

    stack<int> s;
    stack<int> mini;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if ( mini.empty() == true || val <= mini.top() ){
            mini.push(val);
        }
        // else{
        //     if ( mini.top() > val )
        //     mini.push(val);
        // }
    }
    
    void pop() {
        if ( s.empty() == false && s.top() == mini.top() ){
            s.pop();
            mini.pop();
        }
        else if ( s.empty() == false && s.top() != mini.top() )
        s.pop();
        
    }
    
    int top() {
        if ( s.empty() == false )
        return s.top();

        return -1;
    }
    
    int getMin() {
        // stack<int> copy = s;
        // if ( copy.empty() == false ){
        //     int min = INT_MAX;
        //     while ( copy.empty() == false ){
        //         if ( min > copy.top() ){
        //             min = copy.top();
        //             //s.pop();
        //         }
        //         copy.pop();
        //     }
        //    return min;
        // }
        return mini.top();
    }
};
