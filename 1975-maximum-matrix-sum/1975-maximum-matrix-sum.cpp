class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
       long long sum = 0;
    int negative_count = 0;
    int minAbs = INT_MAX;

    for (auto &row : matrix) {
        for (int val : row) {
            sum += abs(val);
            if (val < 0) negative_count++;
            minAbs = min(minAbs, abs(val));
        }
    }

    if (negative_count % 2 == 0) {
        return sum;
    }

      return sum - 2LL * minAbs;
    }
};