class Solution {
public:

    int ar ( stack<int> st ) {
        int ans = 0;
        int count = 1;
        while ( st.empty() == false ) {
            int tmp = st.top() * count ;

            if ( tmp > ans )
            ans = tmp;

            count++;
            st.pop();
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
    //     int min = INT_MAX;
    //     int max = 0;
    //     int idx = -1;

    //     for ( int i = 0 ; i < heights.size() ; i++ ){
    //         if ( min > heights[i] ) {
    //             min = heights[i];
    //             idx = i;
    //         }
    //         if ( max < heights[i] )
    //         max = heights[i];
    //     }

    //    // int area = max;
    //     stack < int > area;
    //     area.push(heights[0]);

    //     for ( int i = 1 ; i < heights.size() ; i++ ){


    //         if ( heights[i-1] <= heights[i] )
    //         area.push(heights[i]);

    //         else   {

    //             if ( ar(area) >= max )
    //             max = ar(area);

    //             while ( area.empty() == false )
    //             area.pop();

    //             area.push(heights[i]);
    //         }

    //         // else if ( ar(area) < max ){
    //         //     while ( )
    //         // }

    //     }

    //     return max;

        int last = heights.size() - 1;
        stack < int > st;
        int max = 0;
        //st.push(heights[last]);
        for ( int i = last  ; i >= 0 ; i-- ) {
            st.push( heights[i] );
            int area = st.top() ;

            for ( int j = i-1 ; j >= 0 ; j-- ) {
                if ( st.top() <= heights[j] ) {
                    area += st.top();
                }
                else 
                break;
            }
            if ( i != last ) {
                for ( int j = i + 1 ; j <= last ; j++ ) {
                    if ( st.top() <= heights[j] ){
                        area += st.top();
                    }
                    else 
                    break;
                }
            }

            if ( area > max )
            max = area;

        }

        return max;
    }
};
