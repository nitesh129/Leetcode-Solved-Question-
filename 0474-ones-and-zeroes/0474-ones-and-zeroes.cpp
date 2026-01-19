class Solution {
public:
    int dp[601][101][101];
    vector<pair<int,int>> cnt;

    int dfs(int i, int zeros, int ones) {
        // Base case
        if (i == cnt.size())
            return 0;

        // Memoized result
        if (dp[i][zeros][ones] != -1)
            return dp[i][zeros][ones];

        // Option 1: skip current string
        int res = dfs(i + 1, zeros, ones);

        // Option 2: take current string (if possible)
        if (zeros >= cnt[i].first && ones >= cnt[i].second) {
            res = max(res,
                      1 + dfs(i + 1,
                              zeros - cnt[i].first,
                              ones - cnt[i].second));
        }

        return dp[i][zeros][ones] = res;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // Count zeros and ones for each string
        for (auto &s : strs) {
            int z = 0, o = 0;
            for (char c : s) {
                if (c == '0') z++;
                else o++;
            }
            cnt.push_back({z, o});
        }

        memset(dp, -1, sizeof(dp));
        return dfs(0, m, n);
    }
};
