class Solution {
public:
    void canvisit(vector<vector<int>>& rooms,int u,vector<bool>&visited){
        visited[u]=true;
        for(int &v : rooms[u]){
            if(!visited[v]){
                canvisit(rooms,v,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        canvisit(rooms,0,visited);
        for(bool x : visited){
            if(x==false) return false;
        }
        return true;
    }
};