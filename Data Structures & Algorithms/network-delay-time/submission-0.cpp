class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto& e : times ) {
            int src = e[0];
            int connect = e[1];
            int weight = e[2];

            adj[src].push_back({connect, weight});
        }
        vector<int> dist(n+1, 1e7);
        dist[k] = 0;

        priority_queue< pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>> > q;
        //dist[node]---node
        q.push({0, k});

        while ( !q.empty() ) {
            int d = q.top().first;
            int node = q.top().second;

            q.pop();

            for ( auto& e : adj[node] ) {
                int newnode = e.first;
                int weight = e.second;

                if ( dist[newnode] > d + weight ) {
                    dist[newnode] = d+ weight;
                    q.push({dist[newnode], newnode});
                }
            }
        }

        int ans = 0;

        for ( int i = 1 ; i <= n ; i++ ) {
            if ( dist[i] >= 1e7 ) return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
        
    }
};
