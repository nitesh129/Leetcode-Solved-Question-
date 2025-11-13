class Solution {
public:
    void dfs(vector<bool>&visited , unordered_map<int ,vector<int>>&adj , vector<int>&componentid,int i,int parent, unordered_map<int,set<int>>&mp){
         visited[i] = true;
         mp[parent].insert(i);
         componentid[i] = parent;
         for(int &v : adj[i]){
             if(!visited[v]){
                 dfs(visited,adj,componentid,v,parent,mp);
             }
         }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int ,vector<int>>adj;
        for(auto&vec : connections){
             int u = vec[0];
             int v = vec[1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
        vector<bool>visited(c+1,false);
        vector<int>componentid(c+1);
        unordered_map<int,set<int>>mp;
        for(int i=1;i<=c;i++){
            if(!visited[i]){
                int component_id = i;
                dfs(visited,adj,componentid,i,component_id,mp);
            }
        }
       vector<int>result;
       for(auto&query : queries){
           int type = query[0];
           int node = query[1];

           if(type == 1){
               int id = componentid[node];
               if(mp[id].count(node)){
                   result.push_back(node);
               }
               else if(!mp[id].empty()){
                   result.push_back(*mp[id].begin());
               }
               else{
                  result.push_back(-1);
               }
           }
           else{
              int id = componentid[node];
              mp[id].erase(node);
           }
       }
       return result;
    }
};