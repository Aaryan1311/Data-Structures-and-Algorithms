class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int> (col,0));
        queue<tuple<int,int,int>> q;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 1;
                    q.push({i,j,0});
                }
            }
        }
        int max_time = 0;
        while(!q.empty()){
            tuple<int,int,int> t = q.front();
            int i = get<0>(t);
            int j = get<1>(t);
            int time = get<2>(t);

            if(i > 0 && visited[i-1][j]  == 0 && grid[i-1][j] == 1){
                q.push({i-1,j,time+1});
                visited[i-1][j] = 1;
                grid[i-1][j] = 2;
            }

            if(j > 0 && visited[i][j-1]  == 0 && grid[i][j-1] == 1){
                q.push({i,j-1,time+1});
                visited[i][j-1] = 1;
                grid[i][j-1] = 2;
            }

            if(i < row-1 && visited[i+1][j]  == 0 && grid[i+1][j] == 1){
                q.push({i+1,j,time+1});
                visited[i+1][j] = 1;
                grid[i+1][j] = 2;
            }

            if(j < col-1 && visited[i][j+1]  == 0 && grid[i][j+1] == 1){
                q.push({i,j+1,time+1});
                visited[i][j+1] = 1;
                grid[i][j+1] = 2;
            }
            max_time = max(time,max_time);
            q.pop();
        }

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return max_time;
    }
};