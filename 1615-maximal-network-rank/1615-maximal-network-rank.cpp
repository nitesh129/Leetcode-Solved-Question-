class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        unordered_set<long long>st;
        for(auto &r : roads){
            degree[r[0]]++;
            degree[r[1]]++;
            // store key btw two nodes to identofy they are of the same path 
            long long key = (long long)r[0]*n+r[1];
            long long key2 = (long long)r[1]*n+r[0];
            st.insert(key);
            st.insert(key2);
        }
        int result =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int rank = degree[i] + degree[j];
                long long key = (long long)i*n+j;
                if(st.count(key)) rank--;
                result = max(result,rank); 
            }
        }
        return result;
    }
};