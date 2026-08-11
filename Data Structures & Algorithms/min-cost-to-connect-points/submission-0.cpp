class Solution {
public:

    int mandist(int x, int y, int i, int j) {
        int dist = 0;

        if ( x-i > 0 ) dist += x-i;
        else dist += i-x;

        if ( y-j > 0 ) dist += y-j;
        else dist += j-y;

        return dist;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> mst(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int ans = 0;

        while ( !pq.empty() ) {
            auto p  = pq.top();
            int d = p.first;
            int idx = p.second;
            int x = points[idx][0];
            int y = points[idx][1];
    
            pq.pop();

            if ( mst[idx] == true ) continue;

            mst[idx] = true;
            ans += d;

            for ( int i = 0 ; i < points.size() ; i++ ) {
                int nx = points[i][0];
                int ny = points[i][1];

                if ( nx == x && ny == y ) continue;

                int dis = mandist(x, y, nx, ny);
                pq.push({dis, i});
                
            }
        }

        return ans;

    }
};
