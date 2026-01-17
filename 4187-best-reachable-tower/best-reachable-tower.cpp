class Solution {
public:

int manhattan(pair<int,int> p1, pair<int,int> p2){
    int dis = abs(p1.first-p2.first) + abs(p1.second-p2.second);
    return dis;
}
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int r) {
        vector<int> ans(2,-1);
        int mnq = INT_MIN;
        for(int i =0;i<towers.size();i++){
            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];
            int dis = manhattan({x,y},{center[0],center[1]});
            if(dis <= r && mnq < q){
                ans[0] = x;
                ans[1] = y;
                mnq = q;
            } 
            else if(dis <= r && mnq == q){
                if(ans[0] > x){
                    ans[0] = x;
                    ans[1] = y;
                }
                else if(ans[0] == x && ans[1] > y){
                    ans[0] = x;
                    ans[1] = y;
                }
            }
        }
        return ans;
    }
};