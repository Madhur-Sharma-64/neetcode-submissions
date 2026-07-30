/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
         sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for ( int i = 0 ;i < n ; i++ ) {
            if ( !minHeap.empty() && intervals[i].start >= minHeap.top() ) {
                minHeap.pop();
            }

            minHeap.push(intervals[i].end);
        }

        return minHeap.size();
    }
};
