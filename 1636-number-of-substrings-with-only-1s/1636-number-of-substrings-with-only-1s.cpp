class Solution {
public:
    int numSub(string s) {
        int modu = 1e9+7;
        int ans =0;
        int n = 0;
        for(char c : s){
            if(c == '0' && n > 0){
               ans = (ans + (__int128)n * (n + 1) / 2 % modu) % modu;
                n=0;
            }
            if(c=='1'){
                n++;
            }
        }
        if(n!=0){
            ans = (ans + (__int128)n * (n + 1) / 2 % modu) % modu;
        }
        return ans;
    }
};