class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &board){
        int n = board.size();
        int m = board[0].size();

        visited[row][col]=1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow < n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
                
                dfs(nrow, ncol, visited, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if (n == 0 || m == 0) return;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        //traverse first row and last row
        for(int i=0;i<m;i++){
            if(!visited[0][i] && board[0][i]=='O'){
                dfs(0, i, visited, board);
            }

            if(!visited[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1, i, visited, board);
            }
        }
         //traverse first col and last col
        for(int i=0;i<n;i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i, 0, visited, board);
            }

            if(!visited[i][m-1] && board[i][m-1]=='O'){
                dfs(i, m-1, visited, board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O')
                  board[i][j]='X';
            }
        }
    }
};
