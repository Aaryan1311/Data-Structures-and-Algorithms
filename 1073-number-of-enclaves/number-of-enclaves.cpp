class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int> (col,0));
        queue<pair<int,int>> q;
        for(int i = 0;i<row;i++){
            if(grid[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
                grid[i][0] = -1;
            }
        }
        for(int i = 0;i<row;i++){
            if(grid[i][col-1] == 1){
                q.push({i,col-1});
                vis[i][col-1] = 1;
                grid[i][col-1] = -1;
            }
        }
        for(int j = 0;j<col;j++){
            if(grid[0][j] == 1){
                q.push({0,j});
                vis[0][j] = 1;
                grid[0][j] = -1;
            }
        }
        for(int j = 0;j<col;j++){
            if(grid[row-1][j] == 1){
                q.push({row-1,j});
                vis[row-1][j] = 1;
                grid[row-1][j] = -1;
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            int i = p.first;
            int j = p.second;

            if(i > 0 && vis[i-1][j] == 0 && grid[i-1][j] == 1){
                vis[i-1][j] = 1;
                grid[i-1][j] = -1;
                q.push({i-1,j});
            }

            if(j > 0 && vis[i][j-1] == 0 && grid[i][j-1] == 1){
                vis[i][j-1] = 1;
                grid[i][j-1] = -1;
                q.push({i,j-1});
            }

            if(i < row-1 && vis[i+1][j] == 0 && grid[i+1][j] == 1){
                vis[i+1][j] = 1;
                grid[i+1][j] = -1;
                q.push({i+1,j});
            }

            if(j < col-1 && vis[i][j+1] == 0 && grid[i][j+1] == 1){
                vis[i][j+1] = 1;
                grid[i][j+1] = -1;
                q.push({i,j+1});
            }
            q.pop();
        }
        int cnt = 0;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};