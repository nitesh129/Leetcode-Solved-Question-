class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
      if (source == target) return 0;

        int n = routes.size();

        // Map each stop to the list of bus routes (indices) that include it
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        // BFS queue: pair of (current stop, buses taken so far)
        queue<pair<int, int>> q;
        q.push({source, 0});

        // To avoid reprocessing the same bus route
        vector<bool> routeVisited(n, false);
        // To avoid reprocessing the same stop too many times
        unordered_set<int> stopVisited;
        stopVisited.insert(source);

        while (!q.empty()) {
            auto [stop, buses] = q.front();
            q.pop();

            // All routes that go through this stop
            if (!stopToRoutes.count(stop)) continue;

            for (int routeIdx : stopToRoutes[stop]) {
                if (routeVisited[routeIdx]) continue;
                routeVisited[routeIdx] = true;  // we are now "taking" this bus

                // From this route, we can go to all its stops
                for (int nextStop : routes[routeIdx]) {
                    if (nextStop == target) {
                        return buses + 1;  // one more bus taken
                    }

                    if (!stopVisited.count(nextStop)) {
                        stopVisited.insert(nextStop);
                        q.push({nextStop, buses + 1});
                    }
                }
            }
        }

        return -1; // target not reachable
    }
};