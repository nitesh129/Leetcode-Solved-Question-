class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        vector<bool> sorted(n - 1, false); // whether strs[i] < strs[i+1] is already determined
        int ans = 0;
        
        for (int c = 0; c < m; c++) {
            bool bad = false;

            // Check if column c breaks lexicographic order
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][c] > strs[i + 1][c]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                ans++; // must delete this column
                continue;
            }

            // Update sorted[] for this column
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][c] < strs[i + 1][c]) {
                    sorted[i] = true;
                }
            }
        }

        return ans;
    }
};
