class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int start = 0;
        int end = arr.size()-1;
        
        int first = -1, last = -1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(arr[mid] == target) {
                first = mid;
                end = mid-1;
            }
            else if(arr[mid] < target) start = mid+1;
            else end = mid-1;
        }
        start = 0;
        end = arr.size()-1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(arr[mid] == target) {
                last = mid;
                start = mid+1;
            }
            else if(arr[mid] < target) start = mid+1;
            else end = mid-1;
        }
        
        if(first == -1 && last == -1) return 0;
        return last-first+1;
        
        
    }
};
