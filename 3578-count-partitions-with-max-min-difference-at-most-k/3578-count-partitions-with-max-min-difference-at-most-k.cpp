class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
       
        const int MOD = 1000000007;
        int n = nums.size();

        // dp[i] = number of ways to partition nums[0..i-1]
        vector<long long> dp(n + 1, 0);
        // pref[i] = dp[0] + ... + dp[i-1], size n+2 so we can safely use pref[i+1]
        vector<long long> pref(n + 2, 0);

        dp[0] = 1;          // empty prefix
        pref[1] = dp[0];    // pref[1] = dp[0]

        deque<int> minD, maxD;  // indices of current window for min and max
        int l = 0;              // left pointer of sliding window

        for (int r = 0; r < n; ++r) {
            // Maintain increasing deque for minimum
            while (!minD.empty() && nums[minD.back()] >= nums[r])
                minD.pop_back();
            minD.push_back(r);

            // Maintain decreasing deque for maximum
            while (!maxD.empty() && nums[maxD.back()] <= nums[r])
                maxD.pop_back();
            maxD.push_back(r);

            // Shrink from left until max - min <= k
            while (!minD.empty() && !maxD.empty() &&
                   (long long)nums[maxD.front()] - nums[minD.front()] > (long long)k) {
                if (minD.front() == l) minD.pop_front();
                if (maxD.front() == l) maxD.pop_front();
                ++l;
            }

            int i = r + 1; // dp index corresponding to prefix [0..r]

            // dp[i] = sum_{j=l..r} dp[j] = pref[r+1] - pref[l]
            long long ways = (pref[i] - pref[l]) % MOD;
            if (ways < 0) ways += MOD;
            dp[i] = ways;

            // Update prefix sum for next iterations: pref[i+1] = sum_{t=0..i} dp[t]
            pref[i + 1] = (pref[i] + dp[i]) % MOD;
        }

        return (int)dp[n];
    }
};