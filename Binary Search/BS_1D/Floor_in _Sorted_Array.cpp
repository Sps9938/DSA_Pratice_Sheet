class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int s = 0;
        int e = arr.size()-1;
        int ans = -1;
        while(s <=e) {
            int mid = s + (e-s)/2;
            
            if(arr[mid] <= x){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
    }
};
