class Solution {
public:
    int t[1001][1001];
    int solve(int indx , int prev ,vector<vector<int>>& pairs , int n){
        if(indx>=n) return 0;
        int take =0;
        int not_take =0;
        if(t[indx][prev+1]!=-1) return t[indx][prev+1];
        if(prev==-1 || pairs[prev][1] < pairs[indx][0]){
            take =  1 + solve(indx+1,indx,pairs,n);
        }
        not_take = solve(indx+1,prev , pairs,n);
        return t[indx][prev+1] = max(take,not_take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        memset(t,-1,sizeof(t));
        sort(begin(pairs),end(pairs));
        return solve(0,-1,pairs,n);
    }
};