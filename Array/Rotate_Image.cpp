class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transpose

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse the row
        for(auto &ma: matrix){
            int left = 0;
            int right = ma.size()-1;

            while(left < right){
                swap(ma[left++], ma[right--]);
            }
        }
    }
};