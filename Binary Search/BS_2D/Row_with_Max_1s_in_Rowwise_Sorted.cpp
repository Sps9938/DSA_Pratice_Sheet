//Simple Approach StirCase Search Algorithm, Where we start from the top right corner of the matrix and move left or down based on the comparison with the target value. 
//Time Complexity: O(n+m), Space Complexity: O(1)
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int row = 0;
        int col = arr[0].size()-1;
        int rowIndex = -1;
        
        while(row < arr.size() && col >= 0) {
            if(arr[row][col] == 1){
                rowIndex = row;
                col--;
            }
            else {
                row++;
            }
        }
        return rowIndex;
    }
};
//Better Approach
//Time Complexity: O(nlogm), Space Complexity: O(1)
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int rowIndex = -1;
        int max1s = 0;
        
        for(int row=0; row<arr.size(); row++) {
            int low = 0;
            int high = arr[0].size()-1;
            while(low <= high) {
                int mid = low+(high-low)/2;
                if(arr[row][mid] == 1) {
                    int count = arr[0].size()-mid;
                    if(count > max1s){
                        max1s = count;
                        rowIndex = row;
                    }
                    high = mid-1;
                }
                else low = mid+1;
            }
        }
        
        return rowIndex;
    }
};