class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int cnt = 0;
        int mn = INT_MAX;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                mn = min(abs(matrix[i][j]),mn);
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) cnt++;
            }
        }
        if(cnt % 2 == 0) return sum;
        else return sum-2*mn;
    }
};