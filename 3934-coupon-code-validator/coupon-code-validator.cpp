class Solution {
public:
    bool checkCode(const string& code) {
        if (code.empty())
            return false;
        for (char c : code) {
            if (!(isalnum(c) || c == '_'))
                return false;
        }
        return true;
    }

    bool checkLine(const string& line) {
        return line == "electronics" || line == "grocery" ||
               line == "pharmacy" || line == "restaurant";
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        unordered_map<string, int> businessOrder = {{"electronics", 0},
                                                    {"grocery", 1},
                                                    {"pharmacy", 2},
                                                    {"restaurant", 3}};

        vector<pair<string, string>> validCoupons;

        for (int i = 0; i < n; i++) {
            if (isActive[i] && checkCode(code[i]) &&
                checkLine(businessLine[i])) {
                validCoupons.push_back({businessLine[i], code[i]});
            }
        }
        sort(validCoupons.begin(), validCoupons.end(),
             [&](const pair<string, string>& a, const pair<string, string>& b) {
                 if (businessOrder[a.first] != businessOrder[b.first])
                     return businessOrder[a.first] < businessOrder[b.first];
                 return a.second < b.second;
             });

        vector<string> result;
        for (const auto& p : validCoupons) {
            result.push_back(p.second);
        }

        return result;
    }
};