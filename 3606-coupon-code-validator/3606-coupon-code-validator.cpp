class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
              int n = code.size();

        // Define business line priority
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<string, string>> validCoupons; // {businessLine, code}

        for (int i = 0; i < n; i++) {
            // Check active
            if (!isActive[i]) continue;

            // Check valid business line
            if (priority.find(businessLine[i]) == priority.end())
                continue;

            // Check code validity
            if (code[i].empty()) continue;

            bool validCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    validCode = false;
                    break;
                }
            }
            if (!validCode) continue;

            validCoupons.push_back({businessLine[i], code[i]});
        }

        // Sort by business line priority, then by code lexicographically
        sort(validCoupons.begin(), validCoupons.end(),
             [&](const pair<string, string>& a,
                 const pair<string, string>& b) {
                 if (priority[a.first] != priority[b.first])
                     return priority[a.first] < priority[b.first];
                 return a.second < b.second;
             });

        // Extract result
        vector<string> result;
        for (auto& p : validCoupons) {
            result.push_back(p.second);
        }

        return result;
    }
};