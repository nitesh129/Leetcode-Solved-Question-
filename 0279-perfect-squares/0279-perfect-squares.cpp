class Solution {
public:
    bool isperfect(int N){
        int r = sqrt(N);
        return r*r==N;
    }
    int numSquares(int n) {
        vector<int>coins;
        for(int i=1;i<=n;i++){
            if(isperfect(i)){
                coins.push_back(i);
            }
        }
        int x = coins.size();
        vector<vector<int>>t(x+1,vector<int>(n+1 , 1e6));
        for(int i=0;i<=x;i++){
            t[i][0] =0;
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=n;j++){
                if(coins[i-1] <=j){
                    t[i][j] = min(1+t[i][j-coins[i-1]] , t[i-1][j]);
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[x][n];
    }
};