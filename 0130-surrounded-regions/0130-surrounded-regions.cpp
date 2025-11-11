class Solution {
public:
    vector<vector<int>>directions{{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(vector<vector<char>>& board,int i,int j,int m,int n){
        board[i][j]='B';
        for(auto & dirr : directions){
             int new_i = i+ dirr[0];
             int new_j = j + dirr[1];
             if(new_i >=0 && new_i<m && new_j>=0 && new_j<n && board[new_i][new_j]=='O'){
                 dfs(board,new_i,new_j,m,n);
             } 
        }
    }
    void convert(vector<vector<char>>& board,int m , int n){
            for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'B') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int j=0;j<n;j++){
            int i=0;
            if(board[i][j]=='O'){
                dfs(board,i,j,m,n);
            } 
            i=m-1;
            if(board[i][j]=='O'){
                dfs(board,i,j,m,n);
            }
        }
        for(int i=0;i<m;i++){
            int j=0;
            if(board[i][j]=='O'){
                dfs(board,i,j,m,n);
            } 
            j=n-1;
            if(board[i][j]=='O'){
                dfs(board,i,j,m,n);
            }
        }
        convert(board,m,n);
    }
};