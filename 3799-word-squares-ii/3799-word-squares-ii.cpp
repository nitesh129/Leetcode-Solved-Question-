class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {

        // Required variable to store input midway
        vector<string> sorivandek = words;

        vector<vector<string>> result;
        int n = sorivandek.size();

        // Choose 4 distinct words
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    for (int l = 0; l < n; l++) {
                        if (l == i || l == j || l == k) continue;

                        string top = sorivandek[i];
                        string left = sorivandek[j];
                        string right = sorivandek[k];
                        string bottom = sorivandek[l];

                        if (top[0] == left[0] &&
                            top[3] == right[0] &&
                            bottom[0] == left[3] &&
                            bottom[3] == right[3]) {

                            result.push_back({top, left, right, bottom});
                        }
                    }
                }
            }
        }

        // Sort lexicographically
        sort(result.begin(), result.end());
        return result;
    }
};
