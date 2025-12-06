class Solution {
public:
   bool isPrime(int  x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    for (int  i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
  }

    bool completePrime(int num) {
    if (!isPrime(num)) return false;

    string s = to_string(num);
    int n = s.size();

    // Check all prefixes and suffixes
    for (int k = 1; k <= n; ++k) {
        int  prefix = stoi(s.substr(0, k));
        int  suffix = stoi(s.substr(n - k, k));

        if (!isPrime(prefix) || !isPrime(suffix)) {
            return false;
        }
    }

    return true;
    }
};