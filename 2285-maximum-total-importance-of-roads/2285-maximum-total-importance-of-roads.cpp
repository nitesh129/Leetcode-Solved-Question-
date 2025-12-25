class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n);
        for(auto & road : roads){
            int u = road[0];
            int v = road[1];
            degree[u]++;
            degree[v]++;
        }
        sort(begin(degree),end(degree));
        long long sum =0;
        int value=1;
        for(int i=0;i<n;i++){
            sum+=degree[i]*(long long)value;
            value++;
        }
        return sum;
    }
};