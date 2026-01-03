class Solution {
public:
     int binaryReflection(int x) {
        int rev = 0;
        while (x > 0) {
            rev = (rev << 1) | (x & 1);
            x >>= 1;
        }
        return rev;
    }
    vector<int> sortByReflection(vector<int>& nums) {
         sort(nums.begin(), nums.end(), [&](int a, int b) {
            int ra = binaryReflection(a);
            int rb = binaryReflection(b);

            if (ra == rb)
                return a < b;     // tie-breaker
            return ra < rb;
        });

        return nums;
    }
};