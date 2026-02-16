class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i][j-1] , t[i-1][j]);
                }
            }
        }
        int ans =0;
        ans+=m - t[m][n];
        ans+=n - t[m][n];
        return ans;
    }
};