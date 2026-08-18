class Twitter {
public:
unordered_map<int, vector<pair<int, int>>> tweet;
unordered_map<int, set<int>> fw;

int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> mh;
        for ( int i = 0 ; i < tweet[userId].size() ; i++ ) {
            int time = tweet[userId][i].first;
            int tweeted = tweet[userId][i].second;

            mh.push({time, tweeted});
        }

        for ( const int& id : fw[userId] ) {
            for ( int i = 0 ; i < tweet[id].size() ; i++ ) {
            int time = tweet[id][i].first;
            int tweeted = tweet[id][i].second;

            mh.push({time, tweeted});
            }
        }

        vector<int> ans;
        int cnt = 0;
        while ( !mh.empty() && cnt < 10 ) {
            ans.push_back(mh.top().second);
            mh.pop();
            cnt++;
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if ( followerId != followeeId )
        fw[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fw[followerId].erase(followeeId);
    }
};
