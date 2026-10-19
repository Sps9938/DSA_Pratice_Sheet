class Solution {
  public:
    int findPivot(vector<int>& nums, int start, int end) {
        if(start == end) return start;

        while(start < end) {
            int mid = start+(end-start)/2;

            if(mid+1 < nums.size() && nums[mid] > nums[mid+1]) return mid;
            else if(mid-1 >=0 && nums[mid] < nums[mid-1]) return mid-1;
            else if(nums[start] < nums[mid]) start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
    int findKRotation(vector<int> &arr) {
        // Code Here
        if(arr.size() == 1) return 0;
        int start = 0;
        int end = arr.size()-1;
        
        int pivot = findPivot(arr, start, end);
        
        return pivot+1;
    }
};
