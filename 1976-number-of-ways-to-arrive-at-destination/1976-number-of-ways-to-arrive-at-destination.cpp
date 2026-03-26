class Solution {
public:
   typedef pair<long long,int> p;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for (auto &road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> result(n, LLONG_MAX);
        vector<int> count(n, 0);

        result[0] = 0;
        count[0] = 1;

        int MOD = 1e9 + 7;

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if (t > result[u]) continue;

            for (auto &it : adj[u]) {
                int ngbr = it.first;
                int time = it.second;

                if (t + time < result[ngbr]) {
                    result[ngbr] = t + time;
                    pq.push({result[ngbr], ngbr});
                    count[ngbr] = count[u];
                }
                else if (t + time == result[ngbr]) {
                    count[ngbr] = (count[ngbr] + count[u]) % MOD;
                }
            }
        }

        return count[n - 1];
        
    }
};