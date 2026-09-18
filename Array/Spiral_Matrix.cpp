class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        
        //right 

        int start_row = 0;
        int start_col = 0;
        int end_col = m-1;
        int end_row = n-1;
        int total_element = m * n;
        int count = 0;
       while(count < total_element ){

                //right
                for(int j=start_col; j<=end_col && count < total_element; j++){
                    ans.push_back(matrix[start_row][j]);
                    count++;
                }
                start_row++;
                
                //down
                for(int i=start_row; i<=end_row && count<total_element; i++){
                    ans.push_back(matrix[i][end_col]);
                    count++;
                }
                end_col--;

                //left
                for(int j=end_col; j>=start_col && count<total_element; j--){
                    ans.push_back(matrix[end_row][j]);
                    count++;
                }
                end_row--;

                //top
                for(int i=end_row; i>=start_row && count<total_element; i--){
                    ans.push_back(matrix[i][start_col]);
                    count++;
                }
                start_col++;
            }


        return ans;

    }
};