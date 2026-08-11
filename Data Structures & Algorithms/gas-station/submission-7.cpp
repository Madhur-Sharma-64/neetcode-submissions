class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int st = n-1;
        int end = 0;
        int tank = gas[st] - cost[st];

        while ( st > end ) {
            if ( tank > 0 ) {
                tank += gas[end] - cost[end];
                end++;
            } else {
                st--;
                tank += gas[st] - cost[st];
            }
        }
        if ( tank >= 0 ) return st;

        return -1;
    }
};
