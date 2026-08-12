class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int st = -1, end = -1;
        wordList.push_back(beginWord);
        st = wordList.size() - 1;
        int n = wordList.size();

        for ( int i = 0 ; i < n ; i++ ) {
            if ( endWord == wordList[i] ) end = i;
        }

        if ( end == -1 ) return 0;

        if (beginWord == endWord) return 1;

        vector<vector<int>> adj(n);
        int len = beginWord.size();
        if ( len != endWord.size() ) return 0;

        for ( int i = 0 ; i < n ; i++ ) {
            string key = wordList[i];
            if ( key.size() != len ) continue;

            for ( int j = i+1 ; j < n ; j++ ) {
                string mapp = wordList[j];

                if ( mapp.size() != len ) continue;
                int diff = 0;
                for ( int cur = 0 ; cur < len ; cur++ ) {
                    if ( mapp[cur] != key[cur] ) diff++;
                }

                if ( diff == 1 ) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> dist(n, INT_MAX);
        dist[st] = 0;

        queue<pair<int, int>> q;
        q.push({dist[st], st});

        while ( !q.empty() ) {
            int idx = q.front().second;
            int d = q.front().first;
            q.pop();

            if ( idx == end ) return d+1;

            for ( auto& e : adj[idx] ) {
                if ( dist[e] > d + 1 ) {
                    dist[e] = d + 1;
                    q.push({dist[e], e});
                }
            }
        }

        return 0;

    }
};
