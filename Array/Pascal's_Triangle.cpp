class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> ans;

      for(int i=1; i<=numRows; i++){
        int value = 1;
        vector<int> temp;
        for(int j=1; j<=i; j++){
            temp.push_back(value);
            value = (value*(i-j))/j;
        }
        ans.push_back(temp);

      }
      return ans;

    }
};
/*class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};

        for(int row=1; row<numRows; row++){
            vector<int> temp(row+1);
            temp[0] = 1;
            temp[temp.size()-1] = 1;

            int i=1;
            while(i<temp.size()-1){
                temp[i] = ans[row-1][i] + ans[row-1][i-1];
                i++;
            }
            ans[row] = temp;
        }
        
        return ans; 

    }
};
*/