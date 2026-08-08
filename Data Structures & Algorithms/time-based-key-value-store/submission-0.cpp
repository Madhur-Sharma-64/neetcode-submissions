class TimeMap {
public:
unordered_map<string, vector<pair<string, int>>> lolu;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        lolu[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        auto& it = lolu[key];

        int l = 0;
        int r = it.size()-1;

        string ans = "";

        while ( l <= r ) {
            int m = (r+l)/2;

            if ( it[m].second == timestamp ) {
                return it[m].first;
            }

            else if ( it[m].second > timestamp ) r = m-1;

            else {
                ans = it[m].first;
                l = m+1;
            }
        }

        return ans;
    }
};
