class Solution {
public:
    vector<int> toposort(unordered_map<int ,vector<int>>&adj , vector<int>&indegree){
         vector<int>result;
         queue<int>que;
         for(int i=0;i<adj.size();i++){
             if(indegree[i]==0){
                que.push(i);
             }
         }
         while(!que.empty()){
             int u = que.front();
             que.pop();
             result.push_back(u);
             for(int &v : adj[u]){
                 indegree[v]--;
                 if(indegree[v]==0){
                    que.push(v);
                 }
             }
         }
         return result.size() == adj.size() ? result : vector<int>();
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i]==-1) group[i]=m++;
        }
        unordered_map<int ,vector<int>>itemgraph;
        vector<int>itemindegree(n,0);
        for(int i=0;i<n;i++){
            itemgraph[i] = vector<int>();
        }
        unordered_map<int ,vector<int>>groupgraph;
        vector<int>groupindegree(m,0);
        for(int i=0;i<m;i++){
            groupgraph[i]= vector<int>();
        }
        for(int i=0;i<n;i++){
            for(int prev : beforeItems[i]){
                itemgraph[prev].push_back(i);
                itemindegree[i]++;

                if(group[prev] != group[i]){
                    int previtemgroup = group[prev];
                    int curritemgroup = group[i];

                    groupgraph[previtemgroup].push_back(curritemgroup);
                    groupindegree[curritemgroup]++;
                }
            }
        }
        vector<int>itemorder = toposort(itemgraph,itemindegree);
        vector<int>grouporder = toposort(groupgraph,groupindegree);
        unordered_map<int,vector<int>>grouptoitem;
        for(int &item : itemorder){
             int itemgroup = group[item];
             grouptoitem[itemgroup].push_back(item);
        }
        vector<int>result;
        for(int &group : grouporder){
            result.insert(result.end(),grouptoitem[group].begin() , grouptoitem[group].end());

        }
        return result;
    }
};