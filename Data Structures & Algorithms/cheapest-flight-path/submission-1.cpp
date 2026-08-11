class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for ( auto& e : flights ) {
            int u = e[0];
            int v = e[1];
            int c = e[2];

            adj[u].push_back({v, c});
        }

        priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq; //minHeap
        //cost----idx-----stops
        vector<vector<int>> cost(n, vector<int>(k+2, 1e8));
        cost[src][0] = 0;
        pq.push({0, src, -1});
        //int stops = -1;

        while ( !pq.empty() ) {
            auto [cst, idx, stops] = pq.top();
            pq.pop();

            if ( idx == dst ) return cst;

            if ( stops > k ) continue;

            for ( auto& e : adj[idx] ) {
                int dest = e.first;
                int price = e.second;
                int newcost = cst+price;
                int newstops = stops+1;

                if(cost[dest][newstops] > newcost && newstops <= k) {
                    cost[dest][newstops] = newcost;
                    pq.push({newcost, dest, newstops});
                }
            }
        }

        if (cost[dst][k] == 1e8 ) return -1;

        return cost[dst][k];
    }
};
