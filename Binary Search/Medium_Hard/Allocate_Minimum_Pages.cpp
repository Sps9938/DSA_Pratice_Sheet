class Solution {
  public:
    int findTotalStudent(vector<int>& arr, int &k, long long &pages) {
        long long totalPage = 0;
        int studentNeeded = 1;
        for(int i=0; i<arr.size(); i++) {
            if(totalPage + arr[i] > pages) {
                studentNeeded++;
                totalPage = 0;
            }
            totalPage += arr[i];
        }
        
        return studentNeeded;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size() < k) return -1;
        int low = INT_MIN;
        long long high = 0;
        for(int i=0; i<arr.size(); i++) {
            low = max(low, arr[i]);
            high += arr[i];
        }
        
        while(low <= high) {
            long long mid = low+(high-low)/2;
            int studentNeeded = findTotalStudent(arr, k, mid);
            if(studentNeeded <= k) high = mid-1;
            else low = mid+1;
        }
        
        return low;
    }
};