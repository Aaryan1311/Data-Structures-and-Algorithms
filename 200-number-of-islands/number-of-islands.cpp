class Solution {
public:
    void dfs(int i, int j, int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[i][j] = 1;
        if(i < row-1 && vis[i+1][j] == 0 && grid[i+1][j] == '1'){
            dfs(i+1,j,row,col,vis,grid);
        }

        if(j < col-1 && vis[i][j+1] == 0 && grid[i][j+1] == '1'){
            dfs(i,j+1,row,col,vis,grid);
        }

        if(i > 0 && vis[i-1][j] == 0 && grid[i-1][j] == '1'){
            dfs(i-1,j,row,col,vis,grid);
        }

        if(j > 0 && vis[i][j-1] == 0 && grid[i][j-1] == '1'){
            dfs(i,j-1,row,col,vis,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int> (col,0));
        for(int i = 0;i < row; i++){
            for(int j = 0;j<col;j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};