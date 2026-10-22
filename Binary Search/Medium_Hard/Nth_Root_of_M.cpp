class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        if(m == 0) return 0;
        int start = 1;
        int end = m;
        
        while(start <= end) {
            int mid = start+(end-start)/2;
            int x = pow(mid,n);
            if(x == m) return mid;
            else if(x > m) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
};