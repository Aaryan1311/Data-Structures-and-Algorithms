class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int colr = image[sr][sc];
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> vis(row, vector<int> (col, 0));
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            pair<int,int> p = q.front();
            int i = p.first;
            int j = p.second;

            if(i < row-1 && vis[i+1][j] == 0 && image[i+1][j] == colr){
                vis[i+1][j] = 1;
                image[i+1][j] = color;
                q.push({i+1,j});
            }

            if(j < col-1 && vis[i][j+1] == 0 && image[i][j+1] == colr){
                vis[i][j+1] = 1;
                image[i][j+1] = color;
                q.push({i,j+1});
            }

            if(i > 0 && vis[i-1][j] == 0 && image[i-1][j] == colr){
                vis[i-1][j] = 1;
                image[i-1][j] = color;
                q.push({i-1,j});
            }

            if(j > 0 && vis[i][j-1] == 0 && image[i][j-1] == colr){
                vis[i][j-1] = 1;
                image[i][j-1] = color;
                q.push({i,j-1});
            }
            q.pop();
        }
        return image;
    }
};