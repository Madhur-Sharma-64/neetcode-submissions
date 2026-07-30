class Solution {
public:

    string encode(vector<string>& strs) {

    if (strs.size() == 0) return "";

    string ans;

    for (int i = 0; i < strs.size(); i++) {
        ans += to_string(strs[i].size());
        ans.push_back('#');

        for (int j = 0; j < strs[i].size(); j++) {
            ans.push_back(strs[i][j]);
        }
    }

    return ans;
}

    vector<string> decode(string s) {

    if (s.size() == 0) return {};

    vector<string> result;

    int count = 0;

    while (count < s.size()) {

        string lenStr;

        while (s[count] != '#') {
            lenStr.push_back(s[count]);
            count++;
        }

        int len = stoi(lenStr);
        count++;  // skip '#'

        string add;

        for (int i = 0; i < len; i++) {
            add.push_back(s[count]);
            count++;
        }

        result.push_back(add);
    }

    return result;
}
};
