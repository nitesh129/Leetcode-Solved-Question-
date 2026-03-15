class Solution {
public:
    int countCommas(int n) {
        string valid = to_string(n);
        if(valid.length() < 4) return 0;
        return n - 999;
    }
};