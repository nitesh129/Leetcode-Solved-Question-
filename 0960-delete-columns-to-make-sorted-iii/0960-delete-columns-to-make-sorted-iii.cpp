class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        vector<int> dp(m, 1); // dp[j] = longest valid subsequence ending at column j

        int ans = 1;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < j; i++) {
                bool ok = true;
                for (int r = 0; r < n; r++) {
                    if (strs[r][i] > strs[r][j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            ans = max(ans, dp[j]);
        }

        return m - ans; // remove all but the longest valid subsequence
    }
};