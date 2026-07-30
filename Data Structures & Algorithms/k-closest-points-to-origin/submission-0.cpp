class Solution {
public:
    long long distance(vector<int>& coordinates) {
        long long x = coordinates[0];
        long long y = coordinates[1];

        return x * x + y * y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, vector<int>>> maxHeap;

        for (auto &point : points) {
            long long dist = distance(point);

            if (maxHeap.size() < k) {
                maxHeap.push({dist, point});
            } else if (dist < maxHeap.top().first) {
                maxHeap.pop();
                maxHeap.push({dist, point});
            }
        }

        vector<vector<int>> res;

        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};