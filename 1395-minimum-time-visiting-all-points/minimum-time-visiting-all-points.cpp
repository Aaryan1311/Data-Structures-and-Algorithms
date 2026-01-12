class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int idx = 1;
        int x = points[0][0];
        int y = points[0][1];
        int ans = 0;
        while(idx < points.size()){
            int xd = abs(points[idx][0] - x);
            int yd = abs(points[idx][1] - y);
            int diff = 0;
            diff = min(xd,yd);
            xd -= diff;
            yd -= diff;
            diff += max(xd,yd);
            x = points[idx][0];
            y = points[idx][1];
            idx++;
            ans += diff;
        }
        return ans;
    }
};