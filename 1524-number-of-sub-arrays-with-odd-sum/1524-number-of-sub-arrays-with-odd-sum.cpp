class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
    long long parity = 0;
    long long even_count = 1;   // IMPORTANT: start with 1
    long long odd_count = 0;
    long long mod = 1e9 + 7;
    long long ans = 0;

    for(int num : arr){
        parity = (parity + num) % 2;

        if(parity == 0){
            ans += odd_count;
            even_count++;
        }
        else{
            ans += even_count;
            odd_count++;
        }

        ans %= mod;   // keep mod inside loop to avoid overflow
    }

    return ans;
    }
};