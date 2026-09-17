class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<bool> row(n, 0);
        vector<bool> col(m, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        //set zero for all row's
        for(int i=0; i<n; i++){
            
            if(row[i]){
                for(int j=0; j<m; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        //set zero for all col's
        for(int j=0; j<m; j++){
            
            if(col[j]){
                for(int i=0; i<n; i++){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};