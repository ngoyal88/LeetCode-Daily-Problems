class Solution {
public:
    vector<int> countMentions(int num, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            int ta = stoi(a[1]), tb = stoi(b[1]);
            if (ta != tb) return ta < tb;
            if (a[0] == b[0]) return false;
            if (a[0] == "OFFLINE") return true;
            if (b[0] == "OFFLINE") return false;
            return a[0] < b[0];
        });
        vector<int> ans(num, 0);
        vector<int> back(num, -1);
        for (auto it : events) {
            int time = stoi(it[1]);
            
            if (it[0] == "MESSAGE") {
                string s1 = it[2];
                string token;
                stringstream ss(s1);
                while (ss >> token) {
                    if (token == "ALL") {
                        for (auto& event : ans)
                            event++;
                    } else if (token == "HERE") {
                        for (int i = 0; i < num; i++) {
                            if (time >= back[i]) {
                                ans[i]++;
                            }
                        }
                    } else if (token.rfind("id", 0) == 0) {
                        int id = stoi(token.substr(2));
                        if (0 <= id && id < num)
                            ans[id]++;
                    }
                }
            } else {
                int id = stoi(it[2]);
                back[id] = time + 60;
            }
        }
        return ans;
    }
};