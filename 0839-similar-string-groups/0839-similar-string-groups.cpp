class Solution {
public:
    bool similiar(string &a , string &b){
        int diff =0;
        for(int i=0;i<a.length();i++){
             if(a[i]!=b[i] && ++diff > 2) return false;
                  
        }
        return true;
    }
    void dfs(int i , vector<string>&strs , vector<bool>&visited){
        visited[i] = true;
        for(int j=0;j<strs.size();j++){
            if(!visited[j] && similiar(strs[i],strs[j])){
                dfs(j,strs,visited);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
       int n = strs.size();
       int groups =0;
       vector<bool>visited(n,false);
       for(int i=0;i<n;i++){
           if(!visited[i]){
               dfs(i,strs,visited);
               groups++;
           }
       }
       return groups++;
    }
};