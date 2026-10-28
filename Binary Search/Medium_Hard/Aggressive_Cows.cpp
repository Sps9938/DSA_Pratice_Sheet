class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int ans) {
        int pos = arr[0];
        
        for(int i=1; i<arr.size(); i++) {
            int diff = arr[i]-pos;
            if(diff >= ans) {
                pos = arr[i];
                k--;
                if(!(k-1)) return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        
        sort(arr.begin(), arr.end());
        
        int low = 1;
        int high = arr[arr.size()-1] - arr[0];
        
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(isPossible(arr, k, mid)) low = mid+1;
            else high = mid-1;
        }
        
        return high;
    }
};