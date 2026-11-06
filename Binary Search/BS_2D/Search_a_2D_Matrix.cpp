//Simple Approach StirCase Search Algorithm, Where we start from the top right corner of the matrix and move left or down based on the comparison with the target value. 
//Time Complexity: O(n+m), Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;F
        int col = n-1;
        while(row < m && col >= 0) {
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};
//Optimized Approach
//Time Complexity: O(log(n*m)), Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = (m*n)-1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            int rowInd = mid/n;
            int colInd = mid%n;

            if(matrix[rowInd][colInd] == target) return true;
            else if(matrix[rowInd][colInd] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};

//Better Approach
//Time Complexity: O(n*logm), Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++) {
            int low = 0, high = n - 1;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(matrix[i][mid] == target)
                    return true;
                else if(matrix[i][mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return false;
    }
};