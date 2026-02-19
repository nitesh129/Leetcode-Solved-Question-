class Solution {
public:
    int N,M,K;
    int MOD = 1e9 +7;
    int t[51][51][101];
    int solve(int indx , int sc , int maxsofar){
        if(indx == N){
            if(sc==K){
                return 1;
            }
            return 0;
        }
        if(t[indx][sc][maxsofar]!=-1) return t[indx][sc][maxsofar];
        int result =0;
        for(int i=1;i<=M;i++){
            if(i>maxsofar){
                result = (result + solve(indx+1,sc+1,i)) % MOD;
            }
            else{
                result =(result + solve(indx+1,sc,maxsofar))%MOD;
            }
        }
        return t[indx][sc][maxsofar] =  result % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K=k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);

    }
};