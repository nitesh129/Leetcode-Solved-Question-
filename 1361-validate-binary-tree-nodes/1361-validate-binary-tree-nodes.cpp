class Solution {
public:
        bool dfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
            if (visited[u]) return true;  // cycle or multiple parent
            visited[u] = true;

            for (int v : adj[u]) {
                if (v == -1) continue;
                if (dfs(v, adj, visited)) return true;
            }

            return false;
        }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
          unordered_map<int, vector<int>> adj;
          vector<int> indegree(n, 0);

    // Build adjacency list and indegree
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                adj[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
                if (indegree[leftChild[i]] > 1) return false;
            }
            if (rightChild[i] != -1) {
                adj[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
                if (indegree[rightChild[i]] > 1) return false;
            }
        }

    // Find root (indegree == 0)
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            if (root != -1) return false; // More than one root
             root = i;
        }
    }
    if (root == -1) return false;  // no root

    // DFS from root
    vector<bool> visited(n, false);
    if (dfs(root, adj, visited)) return false;

    // Check if all nodes are visited and connected
    for (int i = 0; i < n; i++) {
        if (!visited[i]) return false;
    }

    return true;
    }
};