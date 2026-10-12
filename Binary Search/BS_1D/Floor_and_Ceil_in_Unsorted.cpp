class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int fl = INT_MIN, cl = INT_MAX;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] <= x){
                fl = max(fl, arr[i]);
            }
            if(arr[i] >= x){
                cl = min(cl, arr[i]);
            }
        }
        
        if(fl == INT_MIN) fl = -1;
        if(cl == INT_MAX) cl = -1;
        
        return {fl, cl};
    }
};