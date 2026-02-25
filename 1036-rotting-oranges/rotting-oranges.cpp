class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int curr = 0;
        queue<tuple<int,int,int>> q;
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(),0));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            int x,y,time;
            tie(x,y,time) = q.front();
            //left
            if(x > 0 && grid[x][y] == 2){
                if(!vis[x-1][y]){
                    vis[x-1][y] = 1;
                    if(grid[x-1][y] == 1){
                        grid[x-1][y] = 2;
                        q.push({x-1,y,time+1});
                    }
                }
            }
            //right
            if(x < grid.size()-1){
                if(!vis[x+1][y]){
                    vis[x+1][y] = 1;
                    if(grid[x+1][y] == 1) {
                        grid[x+1][y] = 2;
                        q.push({x+1,y,time+1});
                    }
                }
            }
            //up
            if(y > 0){
                if(!vis[x][y-1]){
                    vis[x][y-1] = 1;
                    if(grid[x][y-1] == 1) {
                        grid[x][y-1] = 2;
                        q.push({x,y-1,time+1});
                    }
                }
            }
            //down
            if(y < grid[0].size()-1){
                if(!vis[x][y+1]){
                    vis[x][y+1] = 1;
                    if(grid[x][y+1] == 1) {
                        grid[x][y+1] = 2;
                        q.push({x,y+1,time+1});
                    }
                }
            }
            curr = max(curr,time);
            q.pop();
        }
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return curr;
    }
};