class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long m = grid[0].size();

        long long N = n * m;
        
        long long sum = 0;
        long long sum_sq = 0;
   
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                sum += grid[i][j];
                sum_sq += (long long)grid[i][j] * (long long)grid[i][j];
            }
        }
        
        long long sum_of_n = N*(N+1)/2;
        long long sum_of_n_sq = (N*(N+1)*(2 * N + 1))/6;
        long long x_y = sum - sum_of_n;
        long long x_sq_y_sq = sum_sq - sum_of_n_sq;
        
        long long X_Y = x_sq_y_sq/x_y;
        
        long long two_X = X_Y + x_y;
        
        long long X = two_X/2;
        long long Y = X_Y - X;
        
        return {(int)X, (int)Y};
    }
};