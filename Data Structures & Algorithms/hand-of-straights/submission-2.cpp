class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if ( hand.size() % groupSize != 0 ) return false;

        sort(hand.begin(), hand.end());
        unordered_map<int, int> mp;

        for ( int i = 0 ; i < hand.size() ; i++ ) 
        mp[hand[i]]++;

        int idx = hand[0];
        while ( idx <= hand[hand.size()-1] ) {

            if ( mp[idx] > 0 ) {
                for ( int i = idx ; i < idx + groupSize ; i++ ) {
                    if ( mp[i] == 0 ) return false;
                    mp[i]--;
                }
            }
            if (mp[idx] == 0)
            idx++;
        }

        return true;
        
    }
};
