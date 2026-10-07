class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n = arr.size();
        
        long long sum = 0;
        long long sum_sq = 0;
   
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            sum_sq += (long long)arr[i] * (long long)arr[i];
        }
        
        long long sum_of_n = n*(n+1)/2;
        long long sum_of_n_sq = (n*(n+1)*(2 * n + 1))/6;
        long long x_y = sum - sum_of_n;
        long long x_sq_y_sq = sum_sq - sum_of_n_sq;
        
        long long X_Y = x_sq_y_sq/x_y;
        
        long long two_X = X_Y + x_y;
        
        long long X = two_X/2;
        long long Y = X_Y - X;
        
        return {(int)X, (int)Y};
    }
};