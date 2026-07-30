class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        map<int, double> mp;

        for (int i = 0; i < position.size(); i++) {
            mp[position[i]] = (double)(target - position[i]) / speed[i];
        }

        int ans = 0;
        double fleetTime = 0;

        for (auto it = mp.rbegin(); it != mp.rend(); it++) {

            if (it->second > fleetTime) {
                ans++;
                fleetTime = it->second;
            }
        }

        return ans;
    }
};