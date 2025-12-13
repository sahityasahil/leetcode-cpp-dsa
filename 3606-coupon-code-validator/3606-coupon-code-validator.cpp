class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ans;
        int n = code.size();
        // category ordering
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<pair<int,string>, string>> valid;  
        // ((businessLine_order , code), code_string)

        for (int i = 0; i < n; i++) {
            
            // 1. code must be non-empty
            if (code[i].empty()) continue;

            // 2. check alphanumeric or underscore ONLY
            bool ok = true;
            for (char ch : code[i]) {
                if (!(isalnum(ch) || ch == '_')) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            // 3. businessLine must be valid
            if (order.find(businessLine[i]) == order.end())
                continue;

            // 4. must be active
            if (!isActive[i])
                continue;

            // Store with sorting key
            valid.push_back({{order[businessLine[i]], code[i]}, code[i]});
        }

        // sort by (businessLine_order, code lexicographically)
        sort(valid.begin(), valid.end());

        // extract only the code strings
        for (auto &p : valid) ans.push_back(p.second);

        return ans;
    }
};
