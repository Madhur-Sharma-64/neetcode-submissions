class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        queue<pair<int, int>> q;
        vector<int> count ( 26, 0);

        for ( auto task : tasks ) count[task-'A']++;

        for ( int cnt : count ) {
            if ( cnt > 0 ) maxHeap.push(cnt);
        }

        int time = 1;

        while ( !maxHeap.empty() || !q.empty() ) {
            if ( !maxHeap.empty() ) {
                int x = maxHeap.top() - 1;
                maxHeap.pop();
                if ( x > 0 ) 
                    q.push({time+n, x});

            }

            else {
                time = q.front().first;
            }

            if ( !q.empty() && q.front().first == time ) {
                maxHeap.push(q.front().second);
                q.pop();
            }
            time++;
        }

        return time-1;


    }
};
