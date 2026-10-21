class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int start = 1;
        int end = n/2;
        int ans = 1;
        while(start <= end) {
            int mid = start+(end-start)/2;
            if(mid*mid <= n){
                ans = mid;
                start = mid+1;
            }
            else end = mid-1;
        }
        return ans;
    }
};