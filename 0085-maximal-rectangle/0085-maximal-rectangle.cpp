class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int max_area = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                max_area = max(max_area, arr[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int element = st.top(); st.pop();
            int nse = arr.size();
            int pse = st.empty() ? -1 : st.top();
            max_area = max(max_area, arr[element] * (nse - pse - 1));
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> presum(n, vector<int>(m, 0));
        int max_area = 0;

        // Fill presum matrix (histogram)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    presum[i][j] = (i == 0) ? 1 : presum[i - 1][j] + 1;
                }
            }
        }

        // For each row, treat it as histogram
        for (int i = 0; i < n; i++) {
            max_area = max(max_area, largestRectangleArea(presum[i]));
        }

        return max_area;
    }
};